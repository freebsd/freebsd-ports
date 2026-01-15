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

PORTNAME?=	nvidia-kmod
DISTVERSION?=	${NVIDIA_DISTVERSION}
# Always try to set PORTREVISION as it can be overridden by the slave ports
PORTREVISION?=	0
CATEGORIES=	x11
MASTER_SITES=	NVIDIA/XFree86/FreeBSD-${ARCH_SUFX}/${DISTVERSION}
DISTNAME=	NVIDIA-FreeBSD-${ARCH_SUFX}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	x11@FreeBSD.org
COMMENT?=	kmod part of NVidia graphics card binary drivers for hardware OpenGL rendering
WWW=		https://www.nvidia.com/object/unix.html

LICENSE_FILE=	${WRKSRC}/doc/license.txt
.include "${.CURDIR}/../nvidia-driver/Makefile.version"
.include "${.CURDIR}/../nvidia-driver/Makefile.common"

# the package provides lib32 versions of the libraries, which then depends
# themselves in non existing lib32 libraries, so we don't want the package
# to end up depending on non existing libraries
NO_SHLIB_REQUIRES_GLOB=*:32

# Choose proper distinfo file using PKGNAMESUFFIX for slave ports.
DISTINFO_FILE=	${.CURDIR}/../nvidia-driver${PKGNAMESUFFIX}/distinfo

# Share patches with main part of ports
FILESDIR=	${.CURDIR}/../nvidia-driver/files
PATCHDIR=	${FILESDIR}

USES=		kmod uidfix
.if ${NVVERSION} >= 470.04201
USES+=		tar:xz
.endif
USE_LDCONFIG=	yes

PIE_UNSAFE=	yes

MAKE_ENV=	DEBUG_FLAGS=${DEBUG_FLAGS}
SUB_FILES=	pkg-message
SUB_PATCHES=	extra-patch-src-Makefile \
		extra-patch-src-nv-freebsd.h
.if ${NVVERSION} < 510.03901
SUB_PATCHES+=	extra-patch-src-nvidia_dev.c \
		extra-patch-src-nvidia_pci.c
.endif
.if ${NVVERSION} < 470.25602 || ${NVVERSION} >= 480.00000 && ${NVVERSION} < 530.03002
SUB_PATCHES+=	extra-patch-src-nvidia_subr.c
.endif

# At commit 9562994a7aacee2baae6ddee1a7b558b48ae39ef on main,
# Local sym resolution was disabled by default in kernel linker.
# Explicitly export functions from nvidia.ko to make nvidia-drm-*-kmod
# ports work after the commit. These symbols do not exist in legacy
# versions prior to 580 series.

.if ${NVVERSION} >= 580.00000
SUB_PATCHES+=	extra-patch-src-Makefile-2
.endif

# Temporarily disable GSP firmware as it is known to cause
# issues with suspend/resume
.if ${NVVERSION} >= 565.00000
SUB_PATCHES+=	extra-gsp-patch-src-common-inc-nv_firmware_registry.h
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

OPTIONS_DEFINE=	ACPI_PM LINUX WBINVD
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

CONFLICTS_INSTALL+=	nvidia-kmod*

.include <bsd.port.pre.mk>

pre-patch:
.for p in ${SUB_PATCHES}
	@${SED} 's/%%NVSRC%%/${NVSRC}/g' ${PATCHDIR}/${p}.in > ${WRKDIR}/${p}
.endfor
.for p in ${SUB_PATCHES}
EXTRA_PATCHES+=	${WRKDIR}/${p}
.endfor

post-patch: .SILENT
# Patch only needed for kmod
	${REINPLACE_CMD} -e 's/SUBDIR=\tsrc \\/SUBDIR=\tsrc/' -e '/lib/,/doc/d' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/\.if exists(nvml)/,/\.endif/d' \
		${WRKSRC}/Makefile

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
# Do not execute afterinstall target (prevent automatic module registration
# and "smart" installation of conflicting files heuristics)
	${REINPLACE_CMD} -e 's/afterinstall/&_dontexecute/' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/beforeinstall/&_dontexecute/' \
		${WRKSRC}/lib/Makefile ${WRKSRC}/src/${NVSRC}/Makefile
# Unbreak the build against -Werror,-Wunused-but-set-variable CFLAGS
.if ${NVVERSION} < 450.51
	${REINPLACE_CMD} -e '/void nvidia_dev_dtor/,+8s,.*status.*,,' \
		${WRKSRC}/src/${NVSRC}/nvidia_dev.c
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
# DMAP_MIN_ADDRESS and DMAP_MAX_ADDRESS is deleted from src at commit
# 4dd828c80828637452a8a4e07a64e294c82e5d8b on main branch.
# Note that there are about 10 days of broken window, as the commit
# does not have corresponding version bump.
.if ${OSVERSION} >= 1500051
	${REINPLACE_CMD} -e 's/DMAP_MIN_ADDRESS/kva_layout.dmap_low/' \
		-e 's/DMAP_MAX_ADDRESS/kva_layout.dmap_high/' \
		${WRKSRC}/src/${NVSRC}/nvidia_subr.c
.endif

post-install: .SILENT
# pkg-plist is already overbloated, so use these hacks instead of PLIST_SUB's
.if ${NVVERSION} < 358.009
	${REINPLACE_CMD} -e '/nvidia-modeset\.ko/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 560.02803
	${REINPLACE_CMD} -e '/nvidia_gsp_ga10x_fw\.ko/d' ${TMPPLIST}
	${REINPLACE_CMD} -e '/nvidia_gsp_tu10x_fw\.ko/d' ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
