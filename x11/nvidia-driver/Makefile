# New ports collection makefile for: nvidia-driver
# Date created:        4 December 2002
# Whom:                Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	nvidia-driver
PORTVERSION=	1.0.3203
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.nvidia.com/freebsd/1.0-3203/
DISTNAME=	NVIDIA_FreeBSD-${PORTVERSION:S/0./0-/}

MAINTAINER=	ports@freebsd.org
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering

USE_X_PREFIX=	yes
NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

# XXX Should use ${PKG_INFO} and ${GREP}
XSERVVERSION!=	/usr/sbin/pkg_info -O x11-servers/XFree86-4-Server 2>/dev/null | grep Server- || true
XLIBVERSION!=	/usr/sbin/pkg_info -O x11/XFree86-4-libraries 2>/dev/null | grep libraries- || true

PLIST_SUB=	XSERVVERSION=${XSERVVERSION} XLIBVERSION=${XLIBVERSION} \
		LINUXBASE=${LINUXBASE}

.if !defined(WITHOUT_LINUX)
USE_LINUX=	yes
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
PLIST_SUB+=	FREEBSD5="@comment " FREEBSD4=""
.else
PLIST_SUB+=	FREEBSD5="" FREEBSD4="@comment "
.endif

.if ${OSVERSION} > 500000 && ${OSVERSION} < 500105
IGNORE=		"You need a more recent version of -CURRENT for this driver"
.endif

.if defined(WITH_FREEBSD_AGP) || defined(FORCE_AGP_RATE)
USE_REINPLACE=	yes

post-patch:
.if defined(WITH_FREEBSD_AGP)
	@${REINPLACE_CMD} "s/undef USE_OS_AGP_GART/define USE_OS_AGP_GART/" \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(FORCE_AGP_RATE)
	@${REINPLACE_CMD} "s/4, 0/4, 1/" ${WRKSRC}/src/nvidia_os_registry.c
.endif
.endif

.if defined(WITHOUT_LINUX)
pre-install:
	@${MKDIR} ${LINUXBASE}/usr/lib
.endif

post-install:
.if ${OSVERSION} < 500000
.for dev in 0 1 2 3
	@mknod /dev/nvidia${dev} c 180 ${dev}
	@${CHMOD} 0666 /dev/nvidia${dev}
.endfor
	@mknod /dev/nvidiactl c 180 255
	@${CHMOD} 0666 /dev/nvidiactl
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
