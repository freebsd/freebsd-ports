# ex:ts=8
# New ports collection makefile for:	paragui
# Date Created:			Mar 28, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paragui
PORTVERSION=	1.0.4
PORTREVISION=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://savannah.nongnu.org/download/paragui/stable.pkg/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform high-level application framework and GUI library

LIB_DEPENDS=	physfs-0.1.8:${PORTSDIR}/devel/physfs \
		SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf \
		expat.4:${PORTSDIR}/textproc/expat2

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

SHLIB_VER=	4
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

post-extract:
	@${RM} -f ${WRKSRC}/src/physfs/platform.c

post-patch:
	@${REINPLACE_CMD} -e 's|LT_CURRENT=.*$$|LT_CURRENT=${SHLIB_VER}|g ; \
		 s|`sdl-config |`\$$\{SDL_CONFIG\} |g' ${WRKSRC}/configure
		
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[$][(]SDL_CFLAGS[)]|\$\(PARAGUI_CFLAGS\)|g ; \
		 s|lib/pkgconfig|libdata/pkgconfig|g ; \
		 s|-L[./]*../src|&/.libs |g'

.include <bsd.port.mk>
