# Created by: Stijn Hoop <stijn@win.tue.nl>
# $FreeBSD$
#
# For those wondering why this port is not under `x11-drivers' category,
# have a look at https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=121930.
#
# Starting with version 1.0-7667, NVidia has dropped support for numerous
# "legacy" GPUs.  Consult NVidia README (the Appendix) to find out whether
# you need to use legacy driver version and install one of corresponding
# slave ports instead (`x11/nvidia-driver-340' or `x11/nvidia-driver-304').

PORTNAME=	nvidia-driver
DISTVERSION?=	367.44
# Always try to set PORTREVISION as it can be overridden by the slave ports
PORTREVISION?=	3
CATEGORIES=	x11
MASTER_SITES=	NVIDIA/XFree86/FreeBSD-${ARCH_SUFX}/${DISTVERSION}
DISTNAME=	NVIDIA-FreeBSD-${ARCH_SUFX}-${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering

LICENSE=	NVIDIA
LICENSE_NAME=	License For Customer Use of NVIDIA Software
LICENSE_FILE=	${WRKSRC}/doc/license.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	i386 amd64

ARCH_SUFX=	x86${ARCH:S/i386//:S/amd/_/}
USES=		kmod uidfix
USE_XORG=	x11 xorg-server xext
USE_GL=		gl
USE_LDCONFIG=	yes

# NVIDIA_ROOT is not set in src/Makefile, which results in bogus -I/src
# passed to compiler and broken build on HEAD since r221320 when option
# -Wmissing-include-dirs was added for kernel sources.  Until properly
# fixed upstream (across all versions, including legacy ones), use this
# hack below to universally set NVIDIA_ROOT.  Also provide X11BASE value
# since it is still used by legacy drivers.
MAKE_ENV=	NVIDIA_ROOT=${WRKSRC} X11BASE=${LOCALBASE}
SUB_FILES=	pkg-deinstall pkg-install pkg-message
DOCSDIR=	${PREFIX}/share/doc/NVIDIA_GLX-1.0
MODULESDIR=	lib/xorg/modules
PORTDOCS=	*

# NVVERSION is float since r372065 (integer values become less readable
# after minor version could occupy three digits)
.if ${DISTVERSION:C/[0-9]+//g} == ".."		# major.minor.update
NVVERSION=	${DISTVERSION:S/./.0/:R}${DISTVERSION:E}
.else						# major.minor
.  if ${DISTVERSION:E} < 100
NVVERSION=	${DISTVERSION:S/./.0/}		# allow minor > 99
.  else
NVVERSION=	${DISTVERSION}
.  endif
.endif

.if ${NVVERSION} < 355.006
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-Makefile \
		${FILESDIR}/extra-patch-src-nv-freebsd.h \
		${FILESDIR}/extra-patch-src-nv-misc.h
NVSRC=		.
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_nvidia_Makefile \
		${FILESDIR}/extra-patch-src_nvidia_nv-freebsd.h \
		${FILESDIR}/extra-patch-src_nvidia_nv-misc.h
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

PLIST_SUB+=	LINUXBASE=${LINUXBASE} SHLIB_VERSION=${PORTVERSION} \
		MODULESDIR=${MODULESDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLINUX}
CONFLICTS_INSTALL=	linux[-_]dri-[0-9]* linux-f10-dri-[0-9]*
USES+=		linux
USE_LINUX=	base:build,run xorglibs
PLIST_SUB+=	LINUX=""
.else
PLIST_SUB+=	LINUX="@comment "
# Propagate WITHOUT_LINUX variable down to inner Makefiles
MAKE_ENV+=	WITHOUT_LINUX=yes
.endif

post-patch: .SILENT
# We should support -CURRENT: kill the check
	${REINPLACE_CMD} -e '24,26d' ${WRKSRC}/src/${NVSRC}/nv-freebsd.h
# Adjust Linux headers #include's after FreeBSD src SVN r246085
.if ${OSVERSION} > 1000027
	${REINPLACE_CMD} -E '/#include "machine\/\.\.\/linux(32)?\/linux.h"/ \
		{ x ; s/.*/#include "machine\/..\/..\/compat\/linux\/linux_ioctl.h"/ ; H ; x ; }' \
			${WRKSRC}/src/${NVSRC}/nvidia_linux.c
.endif
# Adjust vm_object locking after FreeBSD src SVN r248084
.if ${OSVERSION} > 1000029
	${REINPLACE_CMD} -e '/#include <vm\/vm_object.h>/ \
		{ x ; s/.*/#include <sys\/rwlock.h>/ ; G ; }' \
			${WRKSRC}/src/${NVSRC}/nv-freebsd.h
	${REINPLACE_CMD} -E 's/(VM_OBJECT_)(UN)?(LOCK)/\1W\2\3/' \
		${WRKSRC}/src/${NVSRC}/nvidia_subr.c
.endif
# Adjust kmem(9) calls after FreeBSD src SVN r254025
.if ${OSVERSION} > 1000040 && ${NVVERSION} < 331.067
	${REINPLACE_CMD} -e '/kmem_/s/kernel_map/kernel_arena/' \
		${WRKSRC}/src/${NVSRC}/nvidia_subr.c
.endif
# Fix CTLFLAG_* values for SYSCTL_ADD_PROC() after FreeBSD src SVN r273377
.if ${OSVERSION} > 1100039 || ${OSVERSION} > 1001501 && ${OSVERSION} < 1100000
	${REINPLACE_CMD} -e '/SYSCTL_ADD_PROC/,/;/ \
		s/^[[:blank:]]*CTLFLAG_RD/CTLTYPE_STRING |&/' \
			${WRKSRC}/src/${NVSRC}/nvidia_sysctl.c
.endif
# Replace d_thread_t (compat shim to support FreeBSD 4) with `struct thread'
	${REINPLACE_CMD} -e 's/d_thread_t/struct thread/' \
		${WRKSRC}/src/${NVSRC}/nvidia_ctl.c ${WRKSRC}/src/${NVSRC}/nvidia_dev.c \
		${WRKSRC}/src/${NVSRC}/nvidia_linux.c
.if ${NVVERSION} >= 358.009
	${REINPLACE_CMD} -e 's/d_thread_t/struct thread/' \
		${WRKSRC}/src/nvidia-modeset/nvidia-modeset-freebsd.c
.endif
# Respect WITHOUT_LINUX setting
	${REINPLACE_CMD} -e 's/exists(\/.*/& \&\& !defined(WITHOUT_LINUX)/' \
		${WRKSRC}/lib/Makefile
# Do not install VDPAU libraries which are provided by `multimedia/libvdpau'
# port for a while now
	${REINPLACE_CMD} -e '/libvdpau[[:blank:]_][^n]/d ; \
		s/name libvdpau/&_nvidia/' ${WRKSRC}/lib/Makefile
# Do not build any binaries (native nvidia-settings and nvidia-xconfig are
# provided by corresponding ports) and manual pages
	${REINPLACE_CMD} -E 's/(extension).*/\1/' ${WRKSRC}/x11/Makefile
	${REINPLACE_CMD} -e '/bin/d ; /man/d' ${WRKSRC}/x11/Makefile
# Also do not install libnvidia-gtk* libraries which are for nvidia-settings
.if ${NVVERSION} >= 346.016
	${REINPLACE_CMD} -e '/libnvidia-gtk/d' ${WRKSRC}/lib/Makefile
.endif
# Adjust installation paths of some conflicting files (shared also between
# libGL, libEGL, libGLESv2, and xorg-server) to ease package manager work
	${REINPLACE_CMD} -e '/LIBDIR/s:xorg/modules/extensions:&/.nvidia:' \
		${WRKSRC}/x11/extension/Makefile
	${REINPLACE_CMD} -e '/LIBDIR/s:lib:&/.nvidia:' \
		${WRKSRC}/lib/libGL/Makefile
.if ${NVVERSION} >= 331.013
	${REINPLACE_CMD} -e '/LIBDIR/s:lib:&/.nvidia:' \
		${WRKSRC}/lib/libEGL/Makefile \
		${WRKSRC}/lib/libGLESv2/Makefile
.endif
# Do not execute afterinstall target (prevent automatic module registration
# and "smart" installation of conflicting files heuristics)
	${REINPLACE_CMD} -e 's/afterinstall/&_dontexecute/' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/beforeinstall/&_dontexecute/' \
		${WRKSRC}/lib/Makefile ${WRKSRC}/src/${NVSRC}/Makefile
# /usr/share/nvidia path is hardcoded in libGL and nvidia-settings, but we
# won't adhere to this stupidity and install nvidia-application-profiles-*
# files as part of documentation
.if ${NVVERSION} >= 334.016
	${REINPLACE_CMD} -e 's,/usr/share/nvidia,${STAGEDIR}${DOCSDIR},' \
		${WRKSRC}/lib/libGL/Makefile ${WRKSRC}/doc/Makefile
.endif
# New cap_rights_t structure was introduced in FreeBSD r255219 (FreeBSD 10.0).
.if ${OSVERSION} < 1000053 && ${NVVERSION} >= 358.009
	${REINPLACE_CMD} '/<sys\/caprights.h>/d ; /cap_rights_t rights/d ; s/cap_rights_init(&rights, CAP_IOCTL)/CAP_IOCTL/' \
		${WRKSRC}/src/nvidia-modeset/nvidia-modeset-freebsd.c
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
.if ${NVVERSION} < 355.006
	${REINPLACE_CMD} -E '/(libEGL_nvidia|GLdispatch|OpenGL)/d' ${TMPPLIST}
.else
	${REINPLACE_CMD} 's/libEGL\.so\.${PORTVERSION}/libEGL.so/' \
		${TMPPLIST}
.endif
.if ${NVVERSION} < 358.009
	${REINPLACE_CMD} '/nvidia-modeset.ko/d' ${TMPPLIST}
.endif
.if ${NVVERSION} >= 361.028
	${REINPLACE_CMD} -E '/(EGL_nvidia\.so|GLESv[12](_CM)?(\.so\.[0-9]+\.[0-9]+))$$/d' \
		${TMPPLIST}
.else
	${REINPLACE_CMD} -E '/\/lib\/libGLESv[12](_CM)?(\.so)?(_nvidia.so(\.[0-9]|\.[0-9]+\.[0-9]+)?)?$$/d ; \
		/libEGL_nvidia\.so\.${PORTVERSION}/d' ${TMPPLIST}
.endif

# Target below can be used instead of standard `makesum' to correctly
# update distinfo (i.e., keeping other driver version entries intact)
.if ${.TARGETS:Mupdate-distinfo}
DISTINFO_FILE=	${MASTERDIR}/distinfo.new
.endif

update-distinfo: makesum .SILENT
	${REINPLACE_CMD} -e '/${ARCH_SUFX}-${NVVERSION:R}/s/^/~/' \
		${MASTERDIR}/distinfo
	${REINPLACE_CMD} -e '/^~SHA256/r ${DISTINFO_FILE}' -e '/^~/d' \
		${MASTERDIR}/distinfo
	${RM} ${DISTINFO_FILE} ${MASTERDIR}/distinfo.bak

.include <bsd.port.mk>
