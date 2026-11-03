PORTNAME=	devilspie2
PORTVERSION=	0.46.20260411
CATEGORIES=	x11-wm
PKGNAMESUFFIX=	-devel

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Window manipulation tool
WWW=		https://www.nongnu.org/devilspie2/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwnck-3.so:x11-toolkits/libwnck3

USES=		gettext gmake gnome lua:53 pkgconfig tar:xz xorg
USE_GITHUB=	yes
GH_ACCOUNT=	dsalt
GH_TAGNAME=	4ee13bf303178bfb0ab353f362197f469c3820b3
USE_GNOME=	glib20 gtk30 intltool
USE_XORG=	x11 xinerama
MAKE_ENV+=	"PKG_CONFIG_PATH=${LOCALBASE}/libdata/pkgconfig"
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/glib-2.0 \
		-I${LUA_INCDIR}
LIBS+=		-L${LOCALBASE}/lib -lX11 -L${LUA_LIBDIR} -llua-${LUA_VER}

CONFLICTS_INSTALL=	devilspie2

PORTDOCS=	AUTHORS README.md TODO

OPTIONS_DEFINE=		DOCS XRANDR
OPTIONS_DEFAULT=	XRANDR

XRANDR_LIB_DEPENDS=	libXrandr.so:x11/libXrandr

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
