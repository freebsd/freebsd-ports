# ex:ts=8
# New ports collection makefile for:	paragui
# Date Created:			Mar 28, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paragui
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.bms-austria.com/pub/paragui/release/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Cross-platform high-level application framework and GUI library

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf \
		expat.4:${PORTSDIR}/textproc/expat2

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

SHLIB_VER=	3
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

post-extract:
	@${RM} -f ${WRKSRC}/src/physfs/platform.c

post-patch:
	${REINPLACE_CMD} -e 's|LT_CURRENT=.*$$|LT_CURRENT=${SHLIB_VER}|g ; \
		 s|`sdl-config |`\$$\{SDL_CONFIG\} |g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[$][(]SDL_CFLAGS[)]|\$\(PARAGUI_CFLAGS\)|g ; \
		 s|lib/pkgconfig|libdata/pkgconfig|g'

.include <bsd.port.mk>
