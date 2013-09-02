# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	paragui
PORTVERSION=	1.1.8
PORTREVISION=	12
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Cross-platform high-level application framework and GUI library(devel)

LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs \
		expat.6:${PORTSDIR}/textproc/expat2 \
		freetype.9:${PORTSDIR}/print/freetype2 \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

CONFLICTS=	paragui-[0-9]*

USES=		pkgconfig
USE_AUTOTOOLS=	libtool
USE_SDL=	sdl image ttf
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CPPFLAGS+=	-I${PREFIX}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${PREFIX}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS}
USE_LDCONFIG=	yes

SHLIB_VER=	4
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
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

.include <bsd.port.mk>
