# New ports collection makefile for:	nvidia-driver
# Date created:				4 December 2002
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	nvidia-driver
PORTVERSION=	1.0.${NVVERSION}
PORTREVISION?=	2
CATEGORIES=	x11
MASTER_SITES=	http://download.nvidia.com/freebsd/1.0-${NVVERSION}/ \
		ftp://download.nvidia.com/freebsd/1.0-${NVVERSION}/ \
		http://download1.nvidia.com/freebsd/1.0-${NVVERSION}/ \
		ftp://download1.nvidia.com/freebsd/1.0-${NVVERSION}/
DISTNAME=	NVIDIA-FreeBSD-x86-${PORTVERSION:S/0./0-/}

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering

USE_X_PREFIX=	yes
NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel
INSTALLS_SHLIB=	yes

NVVERSION=	4365

.include <bsd.port.pre.mk>

# XXX Should use ${PKG_INFO} XXX
#
XSERVVERSION!=	/usr/sbin/pkg_info -O x11-servers/XFree86-4-Server 2>/dev/null | ${GREP} Server- || true
XLIBVERSION!=	/usr/sbin/pkg_info -O x11/XFree86-4-libraries 2>/dev/null | ${GREP} libraries- || true

PLIST_SUB=	XSERVVERSION=${XSERVVERSION} XLIBVERSION=${XLIBVERSION} \
		LINUXBASE=${LINUXBASE} NVVERSION=${NVVERSION}

.if !defined(WITHOUT_LINUX)
USE_LINUX=	yes
.endif

.if ${OSVERSION} < 470000
IGNORE=		"requires FreeBSD -STABLE, version 4.7-RELEASE or later"
.endif

.if ${OSVERSION} < 500000
PLIST_SUB+=	FREEBSD5="@comment " FREEBSD4=""
.else
PLIST_SUB+=	FREEBSD5="" FREEBSD4="@comment "
.endif

pre-everything::
.if !defined(WITH_FREEBSD_AGP)
	@${ECHO_MSG} "Define WITH_FREEBSD_AGP to use FreeBSD AGP GART driver"
.endif
.if !defined(FORCE_AGP_RATE)
	@${ECHO_MSG} "Define FORCE_AGP_RATE to limit the driver to lower speeds"
.endif
.if !defined(WITH_NVIDIA_HACKS)
	@${ECHO_MSG} "Define WITH_NVIDIA_HACKS to enable work-arounds to override basic AGP setup"
.endif

.if defined(WITH_FREEBSD_AGP) || defined(FORCE_AGP_RATE) || defined(WITH_NVIDIA_HACKS) || ${OSVERSION} > 501106
USE_REINPLACE=	yes

post-patch:
. if defined(WITH_FREEBSD_AGP)
	@${REINPLACE_CMD} 's/undef USE_OS_AGP_GART/define USE_OS_AGP_GART/' \
		${WRKSRC}/src/nv-freebsd.h
. endif
. if defined(FORCE_AGP_RATE)
	@${REINPLACE_CMD} 's/NVreg_ReqAGPRate,[[:blank:]]*0/NVreg_ReqAGPRate, 1/' \
		${WRKSRC}/src/nvidia_os_registry.c
. endif
. if defined(WITH_NVIDIA_HACKS)
	@${REINPLACE_CMD} 's/NVreg_UpdateKernelAGP,[[:blank:]]*1/NVreg_UpdateKernelAGP, 0/' \
		${WRKSRC}/src/nvidia_os_registry.c
. endif
. if ${OSVERSION} > 501106
	@${REINPLACE_CMD} 's/PCIR_HEADERTYPE/PCIR_HDRTYPE/' ${WRKSRC}/src/nvidia_sysctl.c
. endif
.endif

pre-install:
.if defined(WITHOUT_LINUX)
	@${MKDIR} ${LINUXBASE}/usr/lib
.endif
	-@(kldstat -n linux || kldload linux)

post-install:
.if ${OSVERSION} < 500000
.for dev in 0 1 2 3
	@rm -f /dev/nvidia${dev}
	@mknod /dev/nvidia${dev} c 180 ${dev}
	@${CHMOD} 0666 /dev/nvidia${dev}
.endfor
	@rm -f /dev/nvidiactl
	@mknod /dev/nvidiactl c 180 255
	@${CHMOD} 0666 /dev/nvidiactl
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
