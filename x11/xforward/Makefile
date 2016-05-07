# Created by: Cy Schubert <cy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xforward
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/
DISTNAME=	${PORTNAME}

WRKSRC=		${WRKDIR}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Provide user-level X forwarding service

LICENSE_FILE=	${WRKSRC}/NOTICE

MAKE_ARGS+=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}
USE_XORG=	x11 xt xaw xmu xt xext sm ice xp xft xau xcb xdmcp xrender
USES=		motif
LIB_DEPENDS=	libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2
PLIST_FILES=	bin/xforward man/man1/xforward.1.gz

OPTIONS_DEFINE=		STATIC
STATIC_ALL_TARGET=	all-static
STATIC_INSTALL_TARGET=	install-static
STATIC_PLIST_FILES=	bin/xforward-static

.include <bsd.port.mk>
