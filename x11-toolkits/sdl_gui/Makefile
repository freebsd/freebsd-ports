# ex:ts=8
# Ports collection makefile for:	sdl_gui
# Date created:			Aug 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl_gui
PORTVERSION=	0.10.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.newimage.com/~rhk/SDL_gui/
DISTNAME=	SDL_gui-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Graphical User Interface library for SDL

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf

USE_SDL=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
INSTALLS_SHLIB=	yes

post-configure:
	${REINPLACE_CMD} -e "s/^CC=\"cc\"/CC=\"${CXX}\"/" ${WRKSRC}/libtool

.include <bsd.port.mk>
