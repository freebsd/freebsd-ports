# ex:ts=8
# New ports collection makefile for:	paragui
# Date Created:			Mar 28, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paragui
PORTVERSION=	1.0.4
PORTREVISION=	10
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform high-level application framework and GUI library

LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs \
		expat.6:${PORTSDIR}/textproc/expat2

CONFLICTS=	paragui-devel-[0-9]*

USE_AUTOTOOLS=	libtool:15
USE_SDL=	sdl image ttf
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

SHLIB_VER=	4
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

PORTSCOUT=	limit:^1\.0\.

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -f ${WRKSRC}/src/physfs/platform.c

post-patch:
	@${REINPLACE_CMD} -e 's|LT_CURRENT=.*$$|LT_CURRENT=${SHLIB_VER}|g ; \
		 s|`sdl-config |`\$$\{SDL_CONFIG\} |g' ${WRKSRC}/configure

	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[$][(]SDL_CFLAGS[)]|\$\(PARAGUI_CFLAGS\)|g ; \
		 s|lib/pkgconfig|libdata/pkgconfig|g ; \
		 s|-L[./]*../src|&/.libs |g ; \
		 s|-release $$(LT_RELEASE)||g'

.include <bsd.port.post.mk>
