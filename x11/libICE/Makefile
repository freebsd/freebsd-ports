PORTNAME=	libICE
PORTVERSION=	1.1.0
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Inter Client Exchange library for X11
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

EXTRACT_SUFX=	.tar.xz
USES=		cpe xorg xorg-cat:lib tar:xz
USE_XORG=	xorgproto xtrans
INSTALL_TARGET=	install-strip
CPE_VENDOR=	freedesktop

.include <bsd.port.mk>
