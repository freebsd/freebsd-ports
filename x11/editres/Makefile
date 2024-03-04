PORTNAME=	editres
PORTVERSION=	1.0.9
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Dynamic resource editor for X Toolkit Applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xt xmu xaw

LIB_DEPENDS+=libxkbfile.so:x11/libxkbfile

GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
