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
DISTVERSION?=	390.87
# Always try to set PORTREVISION as it can be overridden by the slave ports
PORTREVISION?=	2
CATEGORIES=	x11
MASTER_SITES=	NVIDIA/XFree86/FreeBSD-${ARCH_SUFX}/${DISTVERSION}
DISTNAME=	NVIDIA-FreeBSD-${ARCH_SUFX}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

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
PLIST_RE=	# empty
SUB_FILES=	pkg-deinstall pkg-install pkg-message nvidia.conf
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
OPTIONS_SUB=		yes

ACPI_PM_DESC=		ACPI Power Management support
LINUX_DESC=		Linux compatibility support
PAE_DESC=		Physical Address Extensions support
WBINVD_DESC=		Flush CPU caches directly with WBINVD

.if ${NVVERSION} < 310.014
OPTIONS_DEFINE+=	FREEBSD_AGP
FREEBSD_AGP_DESC=	Use FreeBSD AGP GART driver
.endif

LINUX_MASTER_SITES=NVIDIA/XFree86/Linux-${LINUX_ARCH_SUFX}/${DISTVERSION}/:linux
LINUX_DISTFILES=NVIDIA-Linux-${LINUX_ARCH_SUFX}-${DISTVERSION}.run:linux
LINUX_USES=	linux
LINUX_USE=	LINUX=xorglibs

LINUX_ARCH_SUFX=${LINUX_ARCH:S/i386/x86/}
LINUX_LIBDIR=	/usr/lib${LINUX_ARCH:S/i386//:S/x86_64/64/}
LINUX_WRKSRC=	${WRKDIR}/NVIDIA-Linux-${LINUX_ARCH_SUFX}-${DISTVERSION}

LINUX_LIBS=	libcuda.so.${PORTVERSION} \
		libnvcuvid.so.${PORTVERSION} \
		libnvidia-cfg.so.${PORTVERSION} \
		libnvidia-compiler.so.${PORTVERSION} \
		libnvidia-glcore.so.${PORTVERSION} \
		libnvidia-ml.so.${PORTVERSION} \
		libnvidia-opencl.so.${PORTVERSION} \
		libnvidia-tls.so.${PORTVERSION} \
		libvdpau_nvidia.so.${PORTVERSION} \
		tls/libnvidia-tls.so.${PORTVERSION}
LINUX_LINKS=	libcuda.so.${PORTVERSION} libcuda.so.1 \
		libcuda.so.${PORTVERSION} libcuda.so \
		libnvcuvid.so.${PORTVERSION} libnvcuvid.so.1 \
		libnvcuvid.so.${PORTVERSION} libnvcuvid.so \
		libnvidia-cfg.so.${PORTVERSION} libnvidia-cfg.so.1 \
		libnvidia-cfg.so.${PORTVERSION} libnvidia-cfg.so \
		libnvidia-ml.so.${PORTVERSION} libnvidia-ml.so.1 \
		libnvidia-ml.so.${PORTVERSION} libnvidia-ml.so \
		libnvidia-opencl.so.${PORTVERSION} libnvidia-opencl.so.1 \
		libvdpau_nvidia.so.${PORTVERSION} vdpau/libvdpau_nvidia.so.1
LINUX32_LIBS=	libcuda.so.${PORTVERSION} \
		libnvidia-compiler.so.${PORTVERSION} \
		libnvidia-glcore.so.${PORTVERSION} \
		libnvidia-ml.so.${PORTVERSION} \
		libnvidia-opencl.so.${PORTVERSION} \
		libnvidia-tls.so.${PORTVERSION} \
		libvdpau_nvidia.so.${PORTVERSION} \
		tls/libnvidia-tls.so.${PORTVERSION}
LINUX32_LINKS=	libcuda.so.${PORTVERSION} libcuda.so.1 \
		libcuda.so.${PORTVERSION} libcuda.so \
		libnvidia-ml.so.${PORTVERSION} libnvidia-ml.so.1 \
		libnvidia-ml.so.${PORTVERSION} libnvidia-ml.so \
		libnvidia-opencl.so.${PORTVERSION} libnvidia-opencl.so.1 \
		libvdpau_nvidia.so.${PORTVERSION} vdpau/libvdpau_nvidia.so.1
LINUX_PROGS=	nvidia-debugdump nvidia-settings nvidia-smi nvidia-xconfig
LINUX_MANS=	nvidia-settings nvidia-smi nvidia-xconfig
LINUX_DATA=	nvidia.icd /etc/OpenCL/vendors
.if ${NVVERSION} >= 375.010
LINUX_DATA+=	10_nvidia.json /usr/share/glvnd/egl_vendor.d
.else
PLIST_RE+=	'\,${LINUXBASE}/usr/share/glvnd,d'
.endif
.if ${NVVERSION} >= 378.009
LINUX_DATA+=	10_nvidia_wayland.json /usr/share/egl/egl_external_platform.d
.else
PLIST_RE+=	'\,${LINUXBASE}/usr/share/egl,d'
.endif
.if ${NVVERSION} >= 390.042
LINUX_LIBS+=	libEGL.so.1.1.0
LINUX_LINKS+=	libEGL.so.1.1.0 libEGL.so.1
LINUX32_LIBS+=	libEGL.so.1.1.0
LINUX32_LINKS+=	libEGL.so.1.1.0 libEGL.so.1
PLIST_RE+=	'\,${LINUXBASE},s/(libEGL\.so)\.X/\1.1.1.0/'
.elif ${NVVERSION} >= 355.006
LINUX_LIBS+=	libEGL.so.1
LINUX32_LIBS+=	libEGL.so.1
PLIST_RE+=	'\,${LINUXBASE}.*libEGL\.so\.X,d'
.elif ${NVVERSION} >= 331.013
LINUX_LIBS+=	libEGL.so.${PORTVERSION}
LINUX_LINKS+=	libEGL.so.${PORTVERSION} libEGL.so.1
LINUX32_LIBS+=	libEGL.so.${PORTVERSION}
LINUX32_LINKS+=	libEGL.so.${PORTVERSION} libEGL.so.1
PLIST_RE+=	'\,${LINUXBASE},s/(libEGL\.so)\.X/\1.${PORTVERSION}/'
.else
PLIST_RE+=	'\,${LINUXBASE}.*libEGL\.so,d'
.endif
.if ${NVVERSION} >= 361.016
LINUX_LIBS+=	libEGL_nvidia.so.${PORTVERSION}
LINUX_LINKS+=	libEGL_nvidia.so.${PORTVERSION} libEGL_nvidia.so.0
LINUX32_LIBS+=	libEGL_nvidia.so.${PORTVERSION}
LINUX32_LINKS+=	libEGL_nvidia.so.${PORTVERSION} libEGL_nvidia.so.0
.elif ${NVVERSION} >= 355.006
LINUX_LIBS+=	libEGL_nvidia.so.0
PLIST_RE+=	'\,${LINUXBASE}.*libEGL_nvidia\.so\.${PORTVERSION},d'
.else
PLIST_RE+=	'\,${LINUXBASE}.*libEGL_nvidia\.so,d'
.endif
.if ${NVVERSION} >= 390.042
LINUX_LIBS+=	libGL.so.1.7.0
LINUX_LINKS+=	libGL.so.1.7.0 libGL.so.1
LINUX32_LIBS+=	libGL.so.1.7.0
LINUX32_LINKS+=	libGL.so.1.7.0 libGL.so.1
PLIST_RE+=	'\,${LINUXBASE},s/(libGL\.so)\.X/\1.1.7.0/'
.elif ${NVVERSION} >= 361.028
LINUX_LIBS+=	libGL.so.1.0.0
LINUX_LINKS+=	libGL.so.1.0.0 libGL.so.1
LINUX32_LIBS+=	libGL.so.1.0.0
LINUX32_LINKS+=	libGL.so.1.0.0 libGL.so.1
PLIST_RE+=	'\,${LINUXBASE},s/(libGL\.so)\.X/\1.1.0.0/'
.elif ${NVVERSION} >= 361.016
LINUX_LIBS+=	libGL.so.1
LINUX32_LIBS+=	libGL.so.1
PLIST_RE+=	'\,${LINUXBASE}.*libGL\.so\.X,d'
.else
LINUX_LIBS+=	libGL.so.${PORTVERSION}
LINUX_LINKS+=	libGL.so.${PORTVERSION} libGL.so.1
LINUX32_LIBS+=	libGL.so.${PORTVERSION}
LINUX32_LINKS+=	libGL.so.${PORTVERSION} libGL.so.1
PLIST_RE+=	'\,${LINUXBASE},s/(libGL\.so)\.X/\1.${PORTVERSION}/'
.endif
.if ${NVVERSION} >= 390.042
LINUX_LIBS+=	libGLESv1_CM.so.1.2.0 \
		libGLESv2.so.2.1.0
LINUX_LINKS+=	libGLESv1_CM.so.1.2.0 libGLESv1_CM.so.1 \
		libGLESv2.so.2.1.0 libGLESv2.so.2
LINUX32_LIBS+=	libGLESv1_CM.so.1.2.0 \
		libGLESv2.so.2.1.0
LINUX32_LINKS+=	libGLESv1_CM.so.1.2.0 libGLESv1_CM.so.1 \
		libGLESv2.so.2.1.0 libGLESv2.so.2
PLIST_RE+=	'\,${LINUXBASE},s/(libGLESv1_CM\.so)\.X/\1.1.2.0/' \
		'\,${LINUXBASE},s/(libGLESv2\.so)\.X/\1.2.1.0/'
.elif ${NVVERSION} >= 361.016
LINUX_LIBS+=	libGLESv1_CM.so.1 \
		libGLESv2.so.2
LINUX32_LIBS+=	libGLESv1_CM.so.1 \
		libGLESv2.so.2
PLIST_RE+=	'\,${LINUXBASE}.*GLESv(1_CM|2)\.so\.X,d'
.elif ${NVVERSION} >= 331.013
LINUX_LIBS+=	libGLESv1_CM.so.${PORTVERSION} \
		libGLESv2.so.${PORTVERSION}
LINUX_LINKS+=	libGLESv1_CM.so.${PORTVERSION} libGLESv1_CM.so.1 \
		libGLESv2.so.${PORTVERSION} libGLESv2.so.2
LINUX32_LIBS+=	libGLESv1_CM.so.${PORTVERSION} \
		libGLESv2.so.${PORTVERSION}
LINUX32_LINKS+=	libGLESv1_CM.so.${PORTVERSION} libGLESv1_CM.so.1 \
		libGLESv2.so.${PORTVERSION} libGLESv2.so.2
PLIST_RE+=	'\,${LINUXBASE},s/(libGLESv(1_CM|2)\.so)\.X/\1.${PORTVERSION}/'
.else
PLIST_RE+=	'\,${LINUXBASE}.*libGLESv(1_CM|2)\.so,d'
.endif
.if ${NVVERSION} >= 361.016
LINUX_LIBS+=	libGLESv1_CM_nvidia.so.${PORTVERSION} \
		libGLESv2_nvidia.so.${PORTVERSION} \
		libGLX.so.0 \
		libGLX_nvidia.so.${PORTVERSION} \
		libnvidia-fatbinaryloader.so.${PORTVERSION} \
		libnvidia-ptxjitcompiler.so.${PORTVERSION}
LINUX_LINKS+=	libGLESv1_CM_nvidia.so.${PORTVERSION} libGLESv1_CM_nvidia.so.1 \
		libGLESv2_nvidia.so.${PORTVERSION} libGLESv2_nvidia.so.2 \
		libGLX.so.0 libGLX.so \
		libGLX_nvidia.so.${PORTVERSION} libGLX_nvidia.so.0 \
		libGLX_nvidia.so.${PORTVERSION} libGLX_indirect.so.0 \
		libnvidia-ptxjitcompiler.so.${PORTVERSION} libnvidia-ptxjitcompiler.so.1 \
		libnvidia-ptxjitcompiler.so.${PORTVERSION} libnvidia-ptxjitcompiler.so
LINUX32_LIBS+=	libGLESv1_CM_nvidia.so.${PORTVERSION} \
		libGLESv2_nvidia.so.${PORTVERSION} \
		libGLX.so.0 \
		libGLX_nvidia.so.${PORTVERSION} \
		libnvidia-fatbinaryloader.so.${PORTVERSION} \
		libnvidia-ptxjitcompiler.so.${PORTVERSION}
LINUX32_LINKS+=	libGLESv1_CM_nvidia.so.${PORTVERSION} libGLESv1_CM_nvidia.so.1 \
		libGLESv2_nvidia.so.${PORTVERSION} libGLESv2_nvidia.so.2 \
		libGLX.so.0 libGLX.so \
		libGLX_nvidia.so.${PORTVERSION} libGLX_nvidia.so.0 \
		libGLX_nvidia.so.${PORTVERSION} libGLX_indirect.so.0 \
		libnvidia-ptxjitcompiler.so.${PORTVERSION} libnvidia-ptxjitcompiler.so.1 \
		libnvidia-ptxjitcompiler.so.${PORTVERSION} libnvidia-ptxjitcompiler.so
.else
PLIST_RE+=	'\,${LINUXBASE}.*libGLESv(1_CM|2)_nvidia\.so,d' \
		'\,${LINUXBASE}.*libGLX(_nvidia|_indirect)?\.so,d' \
		'\,${LINUXBASE}.*libnvidia-fatbinaryloader\.so,d' \
		'\,${LINUXBASE}.*libnvidia-ptxjitcompiler\.so,d'
.endif
.if ${NVVERSION} >= 355.006
LINUX_LIBS+=	libGLdispatch.so.0 \
		libOpenGL.so.0
LINUX_LINKS+=	libOpenGL.so.0 libOpenGL.so
LINUX32_LIBS+=	libGLdispatch.so.0 \
		libOpenGL.so.0
LINUX32_LINKS+=	libOpenGL.so.0 libOpenGL.so
.else
PLIST_RE+=	'\,${LINUXBASE}.*libGLdispatch\.so,d' \
		'\,${LINUXBASE}.*libOpenGL\.so,d'
.endif
.if ${NVVERSION} >= 387.012
LINUX_LIBS+=	libnvidia-egl-wayland.so.1.0.2
LINUX_LINKS+=	libnvidia-egl-wayland.so.1.0.2 libnvidia-egl-wayland.so.1
PLIST_RE+=	'\,${LINUXBASE},s/(libnvidia-egl-wayland\.so)\.X/\1.1.0.2/'
.elif ${NVVERSION} >= 378.013
LINUX_LIBS+=	libnvidia-egl-wayland.so.1.0.1
LINUX_LINKS+=	libnvidia-egl-wayland.so.1.0.1 libnvidia-egl-wayland.so.1
PLIST_RE+=	'\,${LINUXBASE},s/(libnvidia-egl-wayland\.so)\.X/\1.1.0.1/'
.elif ${NVVERSION} >= 378.009
LINUX_LIBS+=	libnvidia-egl-wayland.so.1.0.0
LINUX_LINKS+=	libnvidia-egl-wayland.so.1.0.0 libnvidia-egl-wayland.so.1
PLIST_RE+=	'\,${LINUXBASE},s/(libnvidia-egl-wayland\.so)\.X/\1.1.0.0/'
.elif ${NVVERSION} >= 364.012
LINUX_LIBS+=	libnvidia-egl-wayland.so.${PORTVERSION}
LINUX_LINKS+=	libnvidia-egl-wayland.so.${PORTVERSION} libnvidia-egl-wayland.so.1
PLIST_RE+=	'\,${LINUXBASE},s/(libnvidia-egl-wayland\.so)\.X/\1.${PORTVERSION}/'
.else
PLIST_RE+=	'\,${LINUXBASE}.*libnvidia-egl-wayland\.so,d'
.endif
.if ${NVVERSION} >= 331.013
LINUX_LIBS+=	libnvidia-eglcore.so.${PORTVERSION} \
		libnvidia-fbc.so.${PORTVERSION} \
		libnvidia-glsi.so.${PORTVERSION} \
		libnvidia-ifr.so.${PORTVERSION}
LINUX_LINKS+=	libnvidia-fbc.so.${PORTVERSION} libnvidia-fbc.so.1 \
		libnvidia-fbc.so.${PORTVERSION} libnvidia-fbc.so \
		libnvidia-ifr.so.${PORTVERSION} libnvidia-ifr.so.1 \
		libnvidia-ifr.so.${PORTVERSION} libnvidia-ifr.so
LINUX32_LIBS+=	libnvidia-eglcore.so.${PORTVERSION} \
		libnvidia-fbc.so.${PORTVERSION} \
		libnvidia-glsi.so.${PORTVERSION} \
		libnvidia-ifr.so.${PORTVERSION}
LINUX32_LINKS+=	libnvidia-fbc.so.${PORTVERSION} libnvidia-fbc.so.1 \
		libnvidia-fbc.so.${PORTVERSION} libnvidia-fbc.so \
		libnvidia-ifr.so.${PORTVERSION} libnvidia-ifr.so.1 \
		libnvidia-ifr.so.${PORTVERSION} libnvidia-ifr.so
.else
PLIST_RE+=	'\,${LINUXBASE}.*libnvidia-(eglcore|fbc|glsi|ifr),d'
.endif
.if ${NVVERSION} >= 310.014
LINUX_LIBS+=	libnvidia-encode.so.${PORTVERSION}
LINUX_LINKS+=	libnvidia-encode.so.${PORTVERSION} libnvidia-encode.so.1 \
		libnvidia-encode.so.${PORTVERSION} libnvidia-encode.so
LINUX32_LIBS+=	libnvidia-encode.so.${PORTVERSION}
LINUX32_LINKS+=	libnvidia-encode.so.${PORTVERSION} libnvidia-encode.so.1 \
		libnvidia-encode.so.${PORTVERSION} libnvidia-encode.so
PLIST_RE+=	'\,${LINUXBASE}.*libXvMCNVIDIA,d'
.else
LINUX_LIBS+=	libXvMCNVIDIA.so.${PORTVERSION}
LINUX_LINKS+=	libXvMCNVIDIA.so.${PORTVERSION} libXvMCNVIDIA_dynamic.so.1 \
		libXvMCNVIDIA.so.${PORTVERSION} libXvMCNVIDIA_dynamic.so
PLIST_RE+=	'\,${LINUXBASE}.*libnvidia-encode,d'
.endif
.if ${NVVERSION} >= 346.016
LINUX_LIBS+=	libnvidia-gtk2.so.${PORTVERSION} \
		libnvidia-gtk3.so.${PORTVERSION}
.else
PLIST_RE+=	'\,${LINUXBASE}.*libnvidia-gtk(2|3)\.so,d'
.endif
.if ${NVVERSION} >= 331.049 && ${NVVERSION} < 352.009
LINUX_DATA+=	monitoring.conf /usr/share/nvidia \
		${WRKSRC}/pci.ids /usr/share/nvidia
.else
PLIST_RE+=	'\,${LINUXBASE}.*monitoring\.conf,d' \
		'\,${LINUXBASE}.*pci\.ids,d'
.endif
.if ${NVVERSION} >= 334.016
LINUX_DATA+=	nvidia-application-profiles-${PORTVERSION}-key-documentation /usr/share/nvidia
.else
PLIST_RE+=	'\,${LINUXBASE}.*application-profiles-${PORTVERSION}-key-documentation,d'
.endif
.if ${NVVERSION} >= 319.012
LINUX_DATA+=	nvidia-application-profiles-${PORTVERSION}-rc /usr/share/nvidia
.else
PLIST_RE+=	'\,${LINUXBASE}.*share/nvidia,d'
.endif
.if ${NVVERSION} >= 319.017
LINUX_PROGS+=	nvidia-cuda-mps-control nvidia-cuda-mps-server \
		nvidia-persistenced
LINUX_MANS+=	nvidia-cuda-mps-control nvidia-persistenced
.else
LINUX_PROGS+=	nvidia-cuda-proxy-control nvidia-cuda-proxy-server
LINUX_MANS+=	nvidia-cuda-proxy-control
PLIST_RE+=	'\,${LINUXBASE},s/cuda-mps/cuda-proxy/' \
		'\,${LINUXBASE}.*nvidia-persistenced,d'
.endif
.if ${NVVERSION} >= 364.012
LINUX_DATA+=	nvidia_icd.json /etc/vulkan/icd.d
.else
PLIST_RE+=	'\,${LINUXBASE}/etc/vulkan,d'
.endif

PLIST_SUB+=	LINUXBASE=${LINUXBASE} \
		LINUX_LIBDIR=${LINUX_LIBDIR} \
		SHLIB_VERSION=${PORTVERSION} \
		MODULESDIR=${MODULESDIR}

.include <bsd.port.pre.mk>

.if ${NVVERSION} >= 310.014
LINUX32_LIBS+=	libnvcuvid.so.${PORTVERSION}
LINUX32_LINKS+=	libnvcuvid.so.${PORTVERSION} libnvcuvid.so.1 \
		libnvcuvid.so.${PORTVERSION} libnvcuvid.so
.elif "${LINUX_ARCH}" == "x86_64"
PLIST_RE+=	'\,${LINUXBASE}/usr/lib/libnvcuvid\.so,d'
.endif

.if "${LINUX_ARCH}" == "x86_64"
PLIST_SUB+=	LINUX32=""
.else
PLIST_SUB+=	LINUX32="@comment "
.endif

post-extract-LINUX-on:
	@(cd ${WRKDIR} && ${SH} \
		${DISTDIR}/NVIDIA-Linux-${LINUX_ARCH_SUFX}-${DISTVERSION}.run \
		--extract-only > /dev/null)

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
# Disable installation of Linux libraries
	${REINPLACE_CMD} -e 's/exists(\/.*/& \&\& 0/' \
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
# Adjust installation path of a conflicting file (shared between
# nvidia-driver and xorg-server) to ease package manager work
	${REINPLACE_CMD} -e '/LIBDIR/s:xorg/modules/extensions:&/.nvidia:' \
		${WRKSRC}/x11/extension/Makefile
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

post-patch-LINUX-on:
.if ${NVVERSION} >= 384.047
	@${SED} 's/__NV_VK_ICD__/libGLX_nvidia.so.0/' \
		${LINUX_WRKSRC}/nvidia_icd.json.template > \
		${LINUX_WRKSRC}/nvidia_icd.json
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MODULESDIR}/drivers \
		${STAGEDIR}${PREFIX}/${MODULESDIR}/extensions

post-install: .SILENT
	${INSTALL_SCRIPT} ${WRKSRC}/obj/nvidia-bug-report.sh \
		${STAGEDIR}${PREFIX}/bin
# pkg-plist is already overbloated, so use these hacks instead of PLIST_SUB's
.if ${NVVERSION} >= 304.128 && ${NVVERSION} < 310.019 || ${NVVERSION} >= 361.016
	${REINPLACE_CMD} -E '\,${LINUXBASE},!{/libvdpau(_trace)?\.so/d;}' \
		${TMPPLIST}
.endif
.if ${NVVERSION} >= 310.019
	${REINPLACE_CMD} -e '\,${LINUXBASE},!{/libXvMCNVIDIA/d;}' ${TMPPLIST}
.else	# some applications need this symlink (see PR ports/72877)
	${LN} -sf libXvMCNVIDIA.so.1 \
		${STAGEDIR}${PREFIX}/lib/libXvMCNVIDIA_dynamic.so.1
.endif
.if ${NVVERSION} < 331.013 || ${ARCH} == amd64 && ${NVVERSION} < 334.016
	${REINPLACE_CMD} -E '\,${LINUXBASE},!{/lib(nvidia-)?(EGL|eglcore|GLESv|glsi)/d;}' \
		${TMPPLIST}
.endif
.if ${NVVERSION} < 352.009
	${REINPLACE_CMD} -E '\,${LINUXBASE},!{/(lib)?nvidia-(debugdump|smi|ml)/d;}' \
		${TMPPLIST}
.endif
.if ${NVVERSION} < 355.006
	${REINPLACE_CMD} -E '\,${LINUXBASE},!{/(libEGL_nvidia|GLdispatch|OpenGL)/d;}' \
		${TMPPLIST}
.else
	${REINPLACE_CMD} '\,${LINUXBASE},!s/libEGL\.so\.${PORTVERSION}/libEGL.so/' \
		${TMPPLIST}
.endif
.if ${NVVERSION} < 358.009
	${REINPLACE_CMD} '/nvidia-modeset.ko/d' ${TMPPLIST}
.endif
.if ${NVVERSION} >= 361.028
	${REINPLACE_CMD} -E '\,${LINUXBASE},!{/(EGL_nvidia\.so|GLESv[12](_CM)?(\.so\.[0-9]+\.[0-9]+))$$/d;}' \
		${TMPPLIST}
.else
	${REINPLACE_CMD} -E '\,${LINUXBASE},!{/\/lib\/libGLESv[12](_CM)?(\.so)?(_nvidia.so(\.[0-9]|\.[0-9]+\.[0-9]+)?)?$$/d ; \
		/libEGL_nvidia\.so\.${PORTVERSION}/d;}' ${TMPPLIST}
.endif
	${REINPLACE_CMD} -E ${PLIST_RE:S/^/-e /} ${TMPPLIST}
# Rename some libraries and install a libmap file to resolve conflict with
# Mesa libraries.
	${LN} -sf libGL-NVIDIA.so.1 \
		${STAGEDIR}${PREFIX}/lib/libGL-NVIDIA.so
	${MV} -f ${STAGEDIR}${PREFIX}/lib/libGL.so.1 \
		${STAGEDIR}${PREFIX}/lib/libGL-NVIDIA.so.1
	${RM} -f ${STAGEDIR}${PREFIX}/lib/libGL.so
.if ${NVVERSION} >= 331.013
	${LN} -sf libEGL-NVIDIA.so.1 \
		${STAGEDIR}${PREFIX}/lib/libEGL-NVIDIA.so
	${MV} -f ${STAGEDIR}${PREFIX}/lib/libEGL.so.1 \
		${STAGEDIR}${PREFIX}/lib/libEGL-NVIDIA.so.1
	${RM} -f ${STAGEDIR}${PREFIX}/lib/libEGL.so
	${LN} -sf libGLESv2-NVIDIA.so.2 \
		${STAGEDIR}${PREFIX}/lib/libGLESv2-NVIDIA.so
	${MV} -f ${STAGEDIR}${PREFIX}/lib/libGLESv2.so.2 \
		${STAGEDIR}${PREFIX}/lib/libGLESv2-NVIDIA.so.2
	${RM} -f ${STAGEDIR}${PREFIX}/lib/libGLESv2.so
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/libmap.d/
	${INSTALL_DATA} ${WRKDIR}/nvidia.conf \
		${STAGEDIR}${PREFIX}/etc/libmap.d/

post-install-LINUX-on:
.for f d in ${LINUX_DATA}
	${MKDIR} ${STAGEDIR}${LINUXBASE}${d}
	${INSTALL_DATA} ${LINUX_WRKSRC}/${f} ${STAGEDIR}${LINUXBASE}${d}
.endfor
	${MKDIR} ${STAGEDIR}${LINUXBASE}/usr/bin
	${INSTALL_SCRIPT} ${LINUX_WRKSRC}/nvidia-bug-report.sh \
		${STAGEDIR}${LINUXBASE}/usr/bin
.for p in ${LINUX_PROGS}
	${INSTALL_PROGRAM} ${LINUX_WRKSRC}/${p} ${STAGEDIR}${LINUXBASE}/usr/bin
.endfor
	${MKDIR} ${STAGEDIR}${LINUXBASE}/usr/share/man/man1
.for m in ${LINUX_MANS}
	${INSTALL_MAN} ${LINUX_WRKSRC}/${m}.1.gz \
		${STAGEDIR}${LINUXBASE}/usr/share/man/man1
.endfor
	${MKDIR} ${STAGEDIR}${LINUXBASE}${LINUX_LIBDIR}/tls
	${MKDIR} ${STAGEDIR}${LINUXBASE}${LINUX_LIBDIR}/vdpau
.for l in ${LINUX_LIBS}
	${INSTALL_LIB} ${LINUX_WRKSRC}/${l} \
		${STAGEDIR}${LINUXBASE}${LINUX_LIBDIR}/${l}
.endfor
.for s t in ${LINUX_LINKS}
	${RLN} ${STAGEDIR}${LINUXBASE}${LINUX_LIBDIR}/${s} \
		${STAGEDIR}${LINUXBASE}${LINUX_LIBDIR}/${t}
.endfor
.if "${LINUX_ARCH}" == "x86_64"
	${MKDIR} ${STAGEDIR}${LINUXBASE}/usr/lib/tls
	${MKDIR} ${STAGEDIR}${LINUXBASE}/usr/lib/vdpau
.for l in ${LINUX32_LIBS}
	${INSTALL_LIB} ${LINUX_WRKSRC}/32/${l} \
		${STAGEDIR}${LINUXBASE}/usr/lib/${l}
.endfor
.for s t in ${LINUX32_LINKS}
	${RLN} ${STAGEDIR}${LINUXBASE}/usr/lib/${s} \
		${STAGEDIR}${LINUXBASE}/usr/lib/${t}
.endfor
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

.include <bsd.port.post.mk>
