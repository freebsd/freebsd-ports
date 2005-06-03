# ex:ts=8
# New ports collection makefile for:	paragui
# Date Created:			Mar 28, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paragui
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/stable.pkg/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform high-level application framework and GUI library

LIB_DEPENDS=	physfs-1.0.0:${PORTSDIR}/devel/physfs \
		expat.5:${PORTSDIR}/textproc/expat2

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
USE_SDL=	sdl image ttf
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

SHLIB_VER=	4
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"does not build on ${ARCH}"
.endif

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
