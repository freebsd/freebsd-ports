# ex:ts=8
# Ports collection makefile for:	sdl_gui
# Date created:			Aug 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl_gui
PORTVERSION=	0.10.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.newimage.com/~rhk/SDL_gui/
DISTNAME=	SDL_gui-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A Graphical User Interface library for SDL

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12 \
		SDL_image:${PORTSDIR}/graphics/sdl_image \
		SDL_ttf:${PORTSDIR}/graphics/sdl_ttf

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

.include <bsd.port.mk>
