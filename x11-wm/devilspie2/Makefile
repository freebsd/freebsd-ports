PORTNAME=	devilspie2
PORTVERSION=	0.43
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.savannah.nongnu.org/releases/devilspie2/
DISTFILES=	${PORTNAME}_${PORTVERSION}-src.tar.gz

MAINTAINER=	bsd@dino.sk
COMMENT=	Window manipulation tool
WWW=		https://www.nongnu.org/devilspie2/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwnck-3.so:x11-toolkits/libwnck3

USES=		gettext gmake gnome lua:51 pkgconfig tar:xz
USE_GNOME=	glib20 gtk30 intltool
MAKE_ENV+=	"PKG_CONFIG_PATH=${LOCALBASE}/libdata/pkgconfig"
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/glib-2.0 \
		-I${LUA_INCDIR}
LIBS+=		-L${LOCALBASE}/lib -lX11 -L${LUA_LIBDIR} -llua-${LUA_VER}

PORTDOCS=	AUTHORS README TODO

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
