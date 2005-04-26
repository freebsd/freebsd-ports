# ex:ts=8
# Ports collection makefile for:	sdl_gui
# Date created:			Aug 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl_gui
PORTVERSION=	0.10.3
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.newimage.com/~rhk/SDL_gui/
DISTNAME=	SDL_gui-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	A Graphical User Interface library for SDL

USE_SDL=	sdl image ttf
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=13
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
INSTALLS_SHLIB=	yes

post-configure:
	${REINPLACE_CMD} -e "s/^CC=\"cc\"/CC=\"${CXX}\"/" ${WRKSRC}/libtool

.include <bsd.port.mk>
