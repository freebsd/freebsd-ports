# ex:ts=8
# New ports collection makefile for:	paragui
# Date Created:			Mar 28, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paragui
PORTVERSION=	0.7.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.bms-austria.com/pub/paragui/release/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_FREETYPE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s,\`sdl-config ,\`${SDL_CONFIG} ,g ; \
		s,SDL/,SDL11/,g" ${WRKSRC}/configure

.include <bsd.port.mk>
