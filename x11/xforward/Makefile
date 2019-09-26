# Created by: Cy Schubert <cy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xforward
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Provide user-level X forwarding service

LICENSE_FILE=	${WRKSRC}/NOTICE

LIB_DEPENDS=	libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2
		
USES=		motif xorg
USE_XORG=	x11 xt xaw xmu xt xext sm ice xft xau xcb xdmcp xrender

MAKE_ARGS=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/xforward man/man1/xforward.1.gz

OPTIONS_DEFINE=		STATIC

STATIC_ALL_TARGET=	all-static
STATIC_INSTALL_TARGET=	install-static
STATIC_PLIST_FILES=	bin/xforward-static

.include <bsd.port.mk>
