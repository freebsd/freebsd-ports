# ex:ts=8
# Ports collection makefile for:	sdl_gui
# Date created:			Aug 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl_gui
PORTVERSION=	0.10.3
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://rhk.dataslab.com/SDL_gui/
DISTNAME=	SDL_gui-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Graphical User Interface library for SDL

USE_AUTOTOOLS=	libtool:15
USE_SDL=	sdl image ttf
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-configure:
	${REINPLACE_CMD} -e "s/^CC=\"cc\"/CC=\"${CXX}\"/" ${WRKSRC}/libtool

.include <bsd.port.mk>
