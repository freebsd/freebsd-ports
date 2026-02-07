PORTNAME=	xditview
PORTVERSION=	1.0.7
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Display ditroff output

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xaw xft xmu xrender xt

GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
