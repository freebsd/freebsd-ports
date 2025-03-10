PORTNAME=	libxkbcommon
PORTVERSION=	1.0.3
DISTVERSIONSUFFIX=	-4.el9
PORTREVISION=	2
CATEGORIES=	x11 linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Keymap handling library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://xkbcommon.org/

USES=		cpe linux:rl9
CPE_VENDOR=	xkbcommon
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL} \
		${PORTNAME}-x11-${DISTVERSIONFULL}

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr

.include <bsd.port.mk>
