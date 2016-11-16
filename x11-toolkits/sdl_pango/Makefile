# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	sdl_pango
PORTVERSION=	0.1.2
PORTREVISION=	10
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/sdlpango/SDL_Pango/${PORTVERSION}
DISTNAME=	SDL_Pango-${PORTVERSION}

PATCH_SITES=	http://zarb.org/~gc/t/
PATCHFILES=	SDL_Pango-0.1.2-API-adds.patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL_Pango is the SDL API to the Pango text rendering engine of GNOME 2.x

LICENSE=	LGPL21

USES=		pkgconfig libtool
USE_SDL=	sdl
USE_GNOME=	pango
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
