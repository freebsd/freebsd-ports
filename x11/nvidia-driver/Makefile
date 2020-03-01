# Created by: Stijn Hoop <stijn@win.tue.nl>
# $FreeBSD$
#
# For those wondering why this port is not under `x11-drivers' category,
# have a look at https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=121930.
#
# Starting with version 1.0-7667, NVidia has dropped support for numerous
# "legacy" GPUs.  Consult NVidia README (the Appendix) to find out whether
# you need to use legacy driver version and install one of corresponding
# slave ports instead (`x11/nvidia-driver-390', `x11/nvidia-driver-340',
# or `x11/nvidia-driver-304').

PORTNAME=	nvidia-driver
DISTVERSION?=	440.64
# Always try to set PORTREVISION as it can be overridden by the slave ports
PORTREVISION?=	0
CATEGORIES=	x11
MASTER_SITES=	NVIDIA/XFree86/FreeBSD-${ARCH_SUFX}/${DISTVERSION}
DISTNAME=	NVIDIA-FreeBSD-${ARCH_SUFX}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering

LICENSE_FILE=	${WRKSRC}/doc/license.txt
.include "${.CURDIR}/../nvidia-driver/Makefile.common"

# Pull GNU sed(1) for "binary" patching of obj/libglvnd/libEGL.so.1 and
# obj/libEGL_nvidia.so.0 (see below)
.if ${NVVERSION} >= 410.057
PATCH_DEPENDS=	gsed:textproc/gsed
.endif

USES=		kmod uidfix xorg
USE_XORG=	x11 xorg-server xext
USE_LDCONFIG=	yes

# NVIDIA_ROOT is not set in src/Makefile, which results in bogus -I/src
# passed to compiler and broken build on HEAD since r221320 when option
# -Wmissing-include-dirs was added for kernel sources.  Until properly
# fixed upstream (across all versions, including legacy ones), use this
# hack below to universally set NVIDIA_ROOT.  Also provide X11BASE value
# since it is still used by legacy drivers.
GLVND_JSON_PATH=	${PREFIX}/share/glvnd/egl_vendor.d
WAYLAND_JSON_PATH=	${PREFIX}/share/egl/egl_external_platform.d
MAKE_ENV=	NVIDIA_ROOT=${WRKSRC} X11BASE=${LOCALBASE} \
		EGL_GLVND_JSON_PATH=${STAGEDIR}${GLVND_JSON_PATH} \
		EGL_WAYLAND_JSON_PATH=${STAGEDIR}${WAYLAND_JSON_PATH}
SUB_FILES=	pkg-message nvidia.conf
.if ${NVVERSION} < 410.057
SUB_FILES+=	pkg-deinstall pkg-install
.endif
SUB_PATCHES=	extra-patch-src-Makefile \
		extra-patch-src-nv-freebsd.h \
		extra-patch-src-nv-misc.h \
		extra-patch-src-nvidia_ctl.c \
		extra-patch-src-nvidia_dev.c \
		extra-patch-src-nvidia_linux.c \
		extra-patch-src-nvidia_pci.c
DOCSDIR=	${PREFIX}/share/doc/NVIDIA_GLX-1.0
MODULESDIR=	lib/xorg/modules
PORTDOCS=	*

.if ${NVVERSION} >= 331.013
SUB_LIST+=	NVGL=""
.else
SUB_LIST+=	NVGL="\# "
.endif

.if ${NVVERSION} < 355.006
NVSRC=		.
.else
NVSRC=		nvidia
.endif

.if ${NVVERSION} >= 358.009
# Initialize memory allocations to avoid spurious "lock re-initialization"
# errors.  A little more detail can be found in bug 201340 starting around
# comment #50.
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_nvidia-modeset_nvidia-modeset-freebsd.c
.endif

OPTIONS_DEFINE=	ACPI_PM LINUX WBINVD DOCS
OPTIONS_DEFINE_i386=	PAE
OPTIONS_DEFAULT=	LINUX

ACPI_PM_DESC=		ACPI Power Management support
LINUX_DESC=		Linux compatibility support
PAE_DESC=		Physical Address Extensions support
WBINVD_DESC=		Flush CPU caches directly with WBINVD

.if ${NVVERSION} < 310.014
OPTIONS_DEFINE+=	FREEBSD_AGP
FREEBSD_AGP_DESC=	Use FreeBSD AGP GART driver
.endif

PLIST_SUB+=	MODULESDIR=${MODULESDIR}

.include <bsd.port.pre.mk>

pre-patch:
.for p in ${SUB_PATCHES}
	@${SED} 's/%%NVSRC%%/${NVSRC}/g' ${PATCHDIR}/${p}.in > ${WRKDIR}/${p}
.endfor
.for p in ${SUB_PATCHES}
EXTRA_PATCHES+=	${WRKDIR}/${p}
.endfor

post-patch: .SILENT
# We should support -CURRENT: kill the check
	${REINPLACE_CMD} -e '24,26d' ${WRKSRC}/src/${NVSRC}/nv-freebsd.h
# Adjust Linux headers #include's after FreeBSD src r246085
	${REINPLACE_CMD} -E '/#include "machine\/\.\.\/linux(32)?\/linux.h"/ \
		{ x ; s/.*/#include "machine\/..\/..\/compat\/linux\/linux_ioctl.h"/ ; H ; x ; }' \
			${WRKSRC}/src/${NVSRC}/nvidia_linux.c
# Fix bogus memset() call
	${REINPLACE_CMD} -e '/memset/s/sizeof(ci/sizeof(*ci/' \
		${WRKSRC}/src/${NVSRC}/nvidia_subr.c
# Chase `sys/capability.h' rename to `sys/capsicum.h' in FreeBSD src r263232
	${REINPLACE_CMD} -e 's:sys/capability\.h:sys/capsicum.h:' \
		${WRKSRC}/src/${NVSRC}/nv-freebsd.h
.if ${NVVERSION} >= 358.009
	${REINPLACE_CMD} -e 's:sys/capability\.h:sys/capsicum.h:' \
		${WRKSRC}/src/nvidia-modeset/nvidia-modeset-freebsd.c
.endif
# KPI of kmem_alloc_contig(),kmem_free() changed in FreeBSD src r338143,r338318
.if ${OSVERSION} >= 1200079
	${REINPLACE_CMD} \
	    -e 's/kmem_alloc_contig(kmem_arena, /kmem_alloc_contig(/' \
	    -e 's/kmem_free(kmem_arena, /kmem_free(/' \
		${WRKSRC}/src/${NVSRC}/nvidia_subr.c
.endif
# Pull the right header after FreeBSD src r347984
.if ${OSVERSION} >= 1300029 && ${NVVERSION} >= 358.009
	${REINPLACE_CMD} -e '/^#include/s:lock\.h:mutex.h:' \
		${WRKSRC}/src/nvidia-modeset/nvidia-modeset-freebsd.c
.endif
# Disable installation of Linux libraries (provided by the corresponding
# `x11/linux-nvidia-libs' port or its slaves)
	${REINPLACE_CMD} -e 's/exists(\/.*/& \&\& 0/' \
		${WRKSRC}/lib/Makefile
# Do not install VDPAU libraries which are provided by `multimedia/libvdpau'
# port for a while now
	${REINPLACE_CMD} -e '/libvdpau[[:blank:]_][^n]/d ; \
		s/name libvdpau/&_nvidia/' ${WRKSRC}/lib/Makefile
# Do not build any binaries (native nvidia-settings and nvidia-xconfig are
# provided by their corresponding ports) and manual pages
	${REINPLACE_CMD} -E 's/(extension).*/\1/' ${WRKSRC}/x11/Makefile
	${REINPLACE_CMD} -e '/bin/d ; /man/d' ${WRKSRC}/x11/Makefile
# Also do not install libnvidia-gtk* libraries which are for nvidia-settings
.if ${NVVERSION} >= 346.016
	${REINPLACE_CMD} -e '/libnvidia-gtk/d' ${WRKSRC}/lib/Makefile
.endif
# Adjust installation path of a conflicting file (shared between
# nvidia-driver and xorg-server) to ease package manager work
.if ${NVVERSION} < 410.057
	${REINPLACE_CMD} -e '/LIBDIR/s:xorg/modules/extensions:&/.nvidia:' \
		${WRKSRC}/x11/extension/Makefile
.endif
# Do not execute afterinstall target (prevent automatic module registration
# and "smart" installation of conflicting files heuristics)
	${REINPLACE_CMD} -e 's/afterinstall/&_dontexecute/' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/beforeinstall/&_dontexecute/' \
		${WRKSRC}/lib/Makefile ${WRKSRC}/src/${NVSRC}/Makefile
# /usr/share/nvidia path is hardcoded in libGL and nvidia-settings, but we
# won't adhere to this stupidity and install nvidia-application-profiles-*
# files as part of documentation
.if ${NVVERSION} >= 410.057
	${REINPLACE_CMD} -e 's,/usr/share/nvidia,$${DESTDIR}${DOCSDIR},' \
		${WRKSRC}/lib/libGLX_nvidia/Makefile ${WRKSRC}/doc/Makefile
	${REINPLACE_CMD} -e '/AUXLINK_LINK/s,\$${DESTDIR},,' \
		${WRKSRC}/lib/libGLX_nvidia/Makefile
	prefix="${PREFIX}" ; padding=$$(($${#prefix}+3)) ; \
	gsed ${REINPLACE_ARGS} -E "s,/etc/glvnd/egl_vendor\.d.{$$padding},${GLVND_JSON_PATH}\x00," \
		${WRKSRC}/obj/libglvnd/libEGL.so.1
.elif ${NVVERSION} >= 334.016
	${REINPLACE_CMD} -e 's,/usr/share/nvidia,$${DESTDIR}${DOCSDIR},' \
		${WRKSRC}/lib/libGL/Makefile ${WRKSRC}/doc/Makefile
.endif
.if ${NVVERSION} >= 415.013
	prefix="${PREFIX}" ; padding=$$(($${#prefix}+3)) ; \
	gsed ${REINPLACE_ARGS} -E "s,/etc/egl/egl_external_platform\.d.{$$padding},${WAYLAND_JSON_PATH}\x00," \
		${WRKSRC}/obj/libEGL_nvidia.so.0
.endif
# Finally, process OPTIONS
.if ${PORT_OPTIONS:MFREEBSD_AGP}
	${REINPLACE_CMD} -E 's/undef (NV_SUPPORT_OS_AGP)/define \1/' \
		${WRKSRC}/src/${NVSRC}/nv-freebsd.h
.endif
.if ${PORT_OPTIONS:MACPI_PM}
	${REINPLACE_CMD} -E 's/undef (NV_SUPPORT_ACPI_PM)/define \1/' \
		${WRKSRC}/src/${NVSRC}/nv-freebsd.h
.endif
.if ! ${PORT_OPTIONS:MLINUX}
	${REINPLACE_CMD} -E 's/define (NV_SUPPORT_LINUX_COMPAT)/undef \1/' \
		${WRKSRC}/src/${NVSRC}/nv-freebsd.h
.  if ${NVVERSION} >= 358.009
	${REINPLACE_CMD} -E 's/define (NVKMS_SUPPORT_LINUX_COMPAT)/undef \1/' \
		${WRKSRC}/src/nvidia-modeset/nvidia-modeset-freebsd.c
.  endif
.endif
.if ${PORT_OPTIONS:MPAE}
	${REINPLACE_CMD} -E 's/undef (NV_SUPPORT_PAE)/define \1/' \
		${WRKSRC}/src/${NVSRC}/nv-freebsd.h
.endif
.if ${PORT_OPTIONS:MWBINVD}
	${REINPLACE_CMD} -E 's/undef (NV_USE_WBINVD)/define \1/' \
		${WRKSRC}/src/${NVSRC}/nv-freebsd.h
.endif
# Conditionally install documentation (but you generally want it)
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -E 's/(x11).*/\1/ ; /doc/d' ${WRKSRC}/Makefile
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MODULESDIR}/drivers \
		${STAGEDIR}${PREFIX}/${MODULESDIR}/extensions

post-install: .SILENT
	${INSTALL_SCRIPT} ${WRKSRC}/obj/nvidia-bug-report.sh \
		${STAGEDIR}${PREFIX}/bin
# pkg-plist is already overbloated, so use these hacks instead of PLIST_SUB's
.if ${NVVERSION} >= 304.128 && ${NVVERSION} < 310.019 || ${NVVERSION} >= 361.016
	${REINPLACE_CMD} -E '/libvdpau(_trace)?\.so/d' ${TMPPLIST}
.endif
.if ${NVVERSION} >= 310.019
	${REINPLACE_CMD} -e '/libXvMCNVIDIA/d' ${TMPPLIST}
.else	# some applications need this symlink (see PR ports/72877)
	${LN} -sf libXvMCNVIDIA.so.1 \
		${STAGEDIR}${PREFIX}/lib/libXvMCNVIDIA_dynamic.so.1
.endif
.if ${NVVERSION} < 331.013 || ${ARCH} == amd64 && ${NVVERSION} < 334.016
	${REINPLACE_CMD} -E '/lib(nvidia-)?(EGL|eglcore|GLESv|glsi)/d' \
		${TMPPLIST}
.endif
.if ${NVVERSION} < 352.009
	${REINPLACE_CMD} -E '/(lib)?nvidia-(debugdump|smi|ml)/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 358.009
	${REINPLACE_CMD} -e '/nvidia-modeset\.ko/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 410.057
	${REINPLACE_CMD} -E '/lib(EGL|GLESv[12].*)_nvidia/d ; \
		/lib(GLX|GLdispatch|OpenGL)/d ; \
		/extensions\/libglxserver_nvidia\.so/d ; \
		/10_nvidia\.json/d' ${TMPPLIST}
.else
	${REINPLACE_CMD} -e '/extensions\/\.nvidia\/libglx/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 415.013
	${REINPLACE_CMD} -e '/libnvidia-egl-wayland\.so/d ; \
		/10_nvidia_wayland\.json/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 440.036
	${REINPLACE_CMD} -e '/lib32\//d' ${TMPPLIST}
.endif
# Rename some libraries and install a libmap file to resolve conflict with
# Mesa libraries.
	${LN} -sf libGL-NVIDIA.so.1 \
		${STAGEDIR}${PREFIX}/lib/libGL-NVIDIA.so
	${MV} -f ${STAGEDIR}${PREFIX}/lib/libGL.so.1 \
		${STAGEDIR}${PREFIX}/lib/libGL-NVIDIA.so.1
	${RM} ${STAGEDIR}${PREFIX}/lib/libGL.so
.if ${NVVERSION} >= 331.013
	${LN} -sf libEGL-NVIDIA.so.1 \
		${STAGEDIR}${PREFIX}/lib/libEGL-NVIDIA.so
	${MV} -f ${STAGEDIR}${PREFIX}/lib/libEGL.so.1 \
		${STAGEDIR}${PREFIX}/lib/libEGL-NVIDIA.so.1
	${RM} ${STAGEDIR}${PREFIX}/lib/libEGL.so
	${LN} -sf libGLESv2-NVIDIA.so.2 \
		${STAGEDIR}${PREFIX}/lib/libGLESv2-NVIDIA.so
	${MV} -f ${STAGEDIR}${PREFIX}/lib/libGLESv2.so.2 \
		${STAGEDIR}${PREFIX}/lib/libGLESv2-NVIDIA.so.2
	${RM} ${STAGEDIR}${PREFIX}/lib/libGLESv2.so
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/libmap.d/
	${INSTALL_DATA} ${WRKDIR}/nvidia.conf \
		${STAGEDIR}${PREFIX}/etc/libmap.d/

.include <bsd.port.post.mk>
