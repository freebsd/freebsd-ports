# For those wondering why this port is not under `x11-drivers' category,
# have a look at https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=121930.
#
# Starting with version 1.0-7667, NVidia has dropped support for numerous
# "legacy" GPUs.  Consult NVidia README (the Appendix) to find out whether
# you need to use legacy driver version and install one of corresponding
# slave ports instead (`x11/nvidia-driver-470', `x11/nvidia-driver-390',
# `x11/nvidia-driver-340', or `x11/nvidia-driver-304').
#
# To simplify testing of new feature branches and beta driver versions,
# the port aims to support building against arbitrary DISTVERSION, i.e.
# ``make DISTVERSION=xxx.yy.zz -DNO_CHECKSUM'' should typically work.

PORTNAME?=	nvidia-driver
DISTVERSION?=	${NVIDIA_DISTVERSION}
# Always try to set PORTREVISION as it can be overridden by the slave ports
PORTREVISION?=	0
CATEGORIES=	x11
MASTER_SITES=	NVIDIA/XFree86/FreeBSD-${ARCH_SUFX}/${DISTVERSION}
DISTNAME=	NVIDIA-FreeBSD-${ARCH_SUFX}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	x11@FreeBSD.org
COMMENT?=	NVidia graphics card binary drivers for hardware OpenGL rendering
WWW=		https://www.nvidia.com/object/unix.html

LICENSE_FILE=	${WRKSRC}/doc/license.txt
.include "${.CURDIR}/../nvidia-driver/Makefile.version"
.include "${.CURDIR}/../nvidia-driver/Makefile.common"

# the package provides lib32 versions of the libraries, which then depends
# themselves in non existing lib32 libraries, so we don't want the package
# to end up depending on non existing libraries
NO_SHLIB_REQUIRES_GLOB=*:32

# Choose proper distinfo file using PKGNAMESUFFIX for slave ports.
# Kept for switching to centralized distinfo with suffixes.
.ifdef PKGNAMESUFFIX
DISTINFO_FILE=	${.CURDIR}/distinfo
.endif

# Pull GNU sed(1) for "binary" patching of obj/libglvnd/libEGL.so.1 and
# obj/libEGL_nvidia.so.0 (see below)
.if ${NVVERSION} >= 410.057
PATCH_DEPENDS=	gsed:textproc/gsed
BUILD_DEPENDS=	pkg-config:devel/pkgconf
LIB_DEPENDS=	libOpenGL.so:graphics/libglvnd
.endif
.if ${NVVERSION} >= 415.013
LIB_DEPENDS+=	libnvidia-egl-wayland.so:graphics/egl-wayland
.endif

USES=		kmod uidfix xorg
.if ${NVVERSION} >= 470.04201
USES+=		tar:xz
.endif
USE_XORG=	x11 xorg-server xext
USE_LDCONFIG=	yes

PIE_UNSAFE=	yes

EGL_JSON_PATH=		${PREFIX}/share/egl/egl_external_platform.d
GLVND_JSON_PATH=	${PREFIX}/share/glvnd/egl_vendor.d
VKICD_PATH=		${PREFIX}/share/vulkan/icd.d
VKLAYERS_PATH=		${PREFIX}/share/vulkan/implicit_layer.d
MAKE_ENV=	DEBUG_FLAGS=${DEBUG_FLAGS} \
		EGL_GLVND_JSON_PATH=${STAGEDIR}${GLVND_JSON_PATH} \
		VKICD_PATH=${STAGEDIR}${VKICD_PATH} \
		VKLAYERS_PATH=${STAGEDIR}${VKLAYERS_PATH}
.if ${NVVERSION} < 495.02905
MAKE_ENV+=	EGL_WAYLAND_JSON_PATH=${STAGEDIR}${EGL_JSON_PATH}
.else
MAKE_ENV+=	EGL_EXTERNAL_PLATFORM_JSON_PATH=${STAGEDIR}${EGL_JSON_PATH}
.endif
SUB_FILES=	pkg-message
.if !defined(LIBGLDIR)
SUB_FILES+=	nvidia.conf
.endif
SUB_PATCHES=	extra-patch-src-Makefile \
		extra-patch-src-nv-freebsd.h
.if ${NVVERSION} < 510.03901
SUB_PATCHES+=	extra-patch-src-nvidia_dev.c \
		extra-patch-src-nvidia_pci.c
.endif
.if ${NVVERSION} < 470.25602 || ${NVVERSION} >= 480.00000 && ${NVVERSION} < 530.03002
SUB_PATCHES+=	extra-patch-src-nvidia_subr.c
.endif

# Temporarily disable GSP firmware as it is known to cause
# issues with suspend/resume
.if ${NVVERSION} >= 565.00000
SUB_PATCHES+=	extra-gsp-patch-src-common-inc-nv_firmware_registry.h
.endif

DOCSDIR=	${PREFIX}/share/doc/NVIDIA_GLX-1.0
MODULESDIR=	lib/xorg/modules
EXTENSIONSDIR=	${MODULESDIR}/extensions/.nvidia
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

.if ${NVVERSION} < 358.009
SUB_LIST+=	KLDNAME=nvidia
.else
SUB_LIST+=	KLDNAME=nvidia-modeset
.endif

.if ${NVVERSION} >= 530.03002 && ${NVVERSION} < 545.00
SUB_PATCHES += extra-patch-src_nvidia-modeset_nvidia-modeset-freebsd.c
.endif
.if ${NVVERSION} < 460.039
.  if ${NVVERSION} >= 358.009
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_nvidia-modeset_nvidia-modeset-freebsd.c
.  endif
SUB_PATCHES+=	extra-patch-src-nvidia_ctl.c \
		extra-patch-src-nvidia_linux.c
.elif ${NVVERSION} < 510.03901
EXTRA_PATCHES+=	${FILESDIR}/460-patch-src-nvidia-nvidia_ctl.c \
		${FILESDIR}/460-patch-src-nvidia-nvidia_linux.c \
		${FILESDIR}/460-patch-src_nvidia-modeset_nvidia-modeset-freebsd.c
.endif
.if ${NVVERSION} < 470.04201
SUB_PATCHES+=	extra-patch-src-nv-misc.h
.endif

OPTIONS_DEFINE=	ACPI_PM LINUX WBINVD DOCS
OPTIONS_DEFINE_i386=	PAE
OPTIONS_DEFAULT=	ACPI_PM LINUX

ACPI_PM_DESC=		ACPI Power Management support
LINUX_DESC=		Linux compatibility support
PAE_DESC=		Physical Address Extensions support
WBINVD_DESC=		Flush CPU caches directly with WBINVD

.if ${NVVERSION} < 310.014
OPTIONS_DEFINE+=	FREEBSD_AGP
FREEBSD_AGP_DESC=	Use FreeBSD AGP GART driver
.endif

PLIST_SUB+=	MODULESDIR=${MODULESDIR}
.if ${NVVERSION} < 410.057
PLIST_SUB+=	EXTENSIONSDIR=${EXTENSIONSDIR}
.else
PLIST_SUB+=	EXTENSIONSDIR="@comment "
.endif

# Not part of the pkg-plist because DISTVERSION is not on PLIST_SUB
.if ${NVVERSION} >= 515.04304
PLIST_FILES+=	lib/libnvidia-wayland-client.so.${DISTVERSION}
.endif

CONFLICTS_INSTALL+=	nvidia-driver*
.if ${PORTNAME} != nvidia-secondary-driver
CONFLICTS_INSTALL+=	nvidia-secondary-driver
.endif

.include <bsd.port.pre.mk>

pre-patch:
.for p in ${SUB_PATCHES}
	@${SED} 's/%%NVSRC%%/${NVSRC}/g' ${PATCHDIR}/${p}.in > ${WRKDIR}/${p}
.endfor
.for p in ${SUB_PATCHES}
EXTRA_PATCHES+=	${WRKDIR}/${p}
.endfor

post-patch: .SILENT
.if ${NVVERSION} >= 390
	${REINPLACE_CMD} -e 's|/man/man1|/share/man/man1|' ${WRKSRC}/nvml/man/Makefile
.endif
# We should support -CURRENT: kill the check (first #if __FreeBSD_version)
	linenum=$$(${SED} -ne '/^#if __FreeBSD_version/ { = ; q ; }' \
		${WRKSRC}/src/${NVSRC}/nv-freebsd.h) ; ${REINPLACE_CMD} \
		-e "$$linenum,+2d" ${WRKSRC}/src/${NVSRC}/nv-freebsd.h
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
.if ${NVVERSION} < 530.03002
	${REINPLACE_CMD} \
	    -e 's/kmem_alloc_contig(kmem_arena, /kmem_alloc_contig(/' \
	    -e 's/kmem_free(kmem_arena, /kmem_free(/' \
		${WRKSRC}/src/${NVSRC}/nvidia_subr.c
.endif
# Pull the right header after FreeBSD src r347984
.if ${NVVERSION} >= 358.009
	${REINPLACE_CMD} -e '/^#include/s:lock\.h:mutex.h:' \
		${WRKSRC}/src/nvidia-modeset/nvidia-modeset-freebsd.c
.endif
# After src df38ada2931f, `sys/module.h' must be included after `sys/param.h'
.if ${NVVERSION} >= 358.009
	@${REINPLACE_CMD} -e '/^#include <sys\/param\.h>/d; \
		/^#include <sys\/module\.h>/ { x; \
		s:^:#include <sys/param.h>:; G; }' \
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
	gsed ${REINPLACE_ARGS} -E "s,/etc/egl/egl_external_platform\.d.{$$padding},${EGL_JSON_PATH}\x00," \
		${WRKSRC}/obj/libEGL_nvidia.so.0
.endif
# Unbreak the build against -Werror,-Wunused-but-set-variable CFLAGS
.if ${NVVERSION} < 450.51
	${REINPLACE_CMD} -e '/void nvidia_dev_dtor/,+8s,.*status.*,,' \
		${WRKSRC}/src/${NVSRC}/nvidia_dev.c
.endif
# Move symlinks under PREFIX
.if ${NVVERSION} >= 525.08902
	${REINPLACE_CMD} -e '/ln/s/$${LOCALBASE}\/lib/../' \
		-e '/LIBDIR/!s/$${LOCALBASE}/$${DESTDIR}$${PREFIX}/' \
		${WRKSRC}/lib/libnvidia-allocator/Makefile
.endif
# After src 2a99dd30dfaa, DRIVER_MODULE should not include nvidia_devclass
.if ${OSVERSION} >= 1400058
	${REINPLACE_CMD} -e '/^DRIVER_MODULE/s/, nvidia_devclass//' \
		${WRKSRC}/src/${NVSRC}/nvidia_pci.c
.endif
# Catch up with pmap_unmapdev() and kmem_*() changes in 14-CURRENT
.if ${OSVERSION} >= 1400070 && (${NVVERSION} < 470.25602  || ${NVVERSION} >= 480.00000 && ${NVVERSION} < 530.03002)
	${REINPLACE_CMD} -e '/pmap_unmapdev/s,(vm_offset_t),,' \
		${WRKSRC}/src/${NVSRC}/nvidia_os.c
	${REINPLACE_CMD} -e '/vm_offset_t virtual_address/s,vm_offset_t ,char *,' \
		${WRKSRC}/src/${NVSRC}/nv-freebsd.h
	${REINPLACE_CMD} -e '/vm_offset_t address;/s,vm_offset_t ,void *,' \
		${WRKSRC}/src/${NVSRC}/nvidia_subr.c
.endif
# Fix a K&R prototype
.if ${NVVERSION:R} >= 390
	${REINPLACE_CMD} -e '/nvlink_allocLock/s,(),(void),' \
		${WRKSRC}/src/${NVSRC}/nvlink_freebsd.c
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
# DMAP_MIN_ADDRESS and DMAP_MAX_ADDRESS is deleted from src at commit
# 4dd828c80828637452a8a4e07a64e294c82e5d8b on main branch.
# Note that there are about 10 days of broken window, as the commit
# does not have corresponding version bump.
.if ${OSVERSION} >= 1500051
	${REINPLACE_CMD} -e 's/DMAP_MIN_ADDRESS/kva_layout.dmap_low/' \
		-e 's/DMAP_MAX_ADDRESS/kva_layout.dmap_high/' \
		${WRKSRC}/src/${NVSRC}/nvidia_subr.c
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MODULESDIR}/drivers \
		${STAGEDIR}${PREFIX}/${MODULESDIR}/extensions

post-install: .SILENT
	${INSTALL_SCRIPT} ${WRKSRC}/obj/nvidia-bug-report.sh \
		${STAGEDIR}${PREFIX}/bin
# pkg-plist is already overbloated, so use these hacks instead of PLIST_SUB's
.if ${NVVERSION:R} < 460
	${REINPLACE_CMD} -e '/libnvidia-glvkspirv\.so/d ; \
		/nvidia_icd\.json/d ; /nvidia_layers\.json/d' ${TMPPLIST}
.endif
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
.elif ${NVVERSION} < 465.01901
	${REINPLACE_CMD} -e '/lib32\/libnvidia-glvkspirv\.so/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 470.074 || ${NVVERSION} >= 545.000
	${REINPLACE_CMD} -e '/libnvidia-vulkan-producer\.so/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 495.02905
	${REINPLACE_CMD} -e '/libnvidia-egl-gbm\.so/d ; \
		/15_nvidia_gbm\.json/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 525.08902
	${REINPLACE_CMD} -e '/libnvidia-allocator\.so/d ; \
		/nvidia-drm_gbm\.so/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 545.000
	${REINPLACE_CMD} -e '/libnvidia-gpucomp\.so/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 560.02803
	${REINPLACE_CMD} -e '/nvidia_gsp_ga10x_fw\.ko/d' ${TMPPLIST}
	${REINPLACE_CMD} -e '/nvidia_gsp_tu10x_fw\.ko/d' ${TMPPLIST}
.endif

.if ${NVVERSION} < 410.057
# Rename some libraries and install a libmap file to resolve conflict with
# Mesa libraries.
	${LN} -sf libGL-NVIDIA.so.1 \
		${STAGEDIR}${PREFIX}/lib/libGL-NVIDIA.so
	${MV} -f ${STAGEDIR}${PREFIX}/lib/libGL.so.1 \
		${STAGEDIR}${PREFIX}/lib/libGL-NVIDIA.so.1
	${RM} ${STAGEDIR}${PREFIX}/lib/libGL.so
.  if ${NVVERSION} >= 331.013
	${LN} -sf libEGL-NVIDIA.so.1 \
		${STAGEDIR}${PREFIX}/lib/libEGL-NVIDIA.so
	${MV} -f ${STAGEDIR}${PREFIX}/lib/libEGL.so.1 \
		${STAGEDIR}${PREFIX}/lib/libEGL-NVIDIA.so.1
	${RM} ${STAGEDIR}${PREFIX}/lib/libEGL.so
	${RM} ${STAGEDIR}${PREFIX}/lib/libGLESv1_CM.so
	${RM} ${STAGEDIR}${PREFIX}/lib/libGLESv1_CM.so.1
	${LN} -sf libGLESv2-NVIDIA.so.2 \
		${STAGEDIR}${PREFIX}/lib/libGLESv2-NVIDIA.so
	${MV} -f ${STAGEDIR}${PREFIX}/lib/libGLESv2.so.2 \
		${STAGEDIR}${PREFIX}/lib/libGLESv2-NVIDIA.so.2
	${RM} ${STAGEDIR}${PREFIX}/lib/libGLESv2.so
.  endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/libmap.d/
	${INSTALL_DATA} ${WRKDIR}/nvidia.conf \
		${STAGEDIR}${PREFIX}/etc/libmap.d/
.else
	${REINPLACE_CMD} -E '/-NVIDIA/d ; \
		/lib(Open)?E?GLX?(ESv[12](_CM)?|dispatch)?\.so/d' \
		${TMPPLIST}
# Override mesa.conf if GLX_EXT_libglvnd is missing
	@${ECHO_CMD} "libGLX_indirect.so.0 libGLX_nvidia.so.0" \
		>${STAGEDIR}${PREFIX}/etc/libmap.d/nvidia.conf
.endif

.include <bsd.port.post.mk>
