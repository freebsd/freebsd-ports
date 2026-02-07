PORTNAME=	jgmenu
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Simple X11 menu
WWW=		https://jgmenu.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png

USES=		compiler:c11 gmake gnome pkgconfig python shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	johanmalm
USE_GNOME=	cairo gdkpixbuf glib20 librsvg2 libxml2 pango
USE_XORG=	x11 xrandr

SHEBANG_FILES=		contrib/gtktheme/*.py contrib/pmenu/*.py src/*.py
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec \
			--prefix=${PREFIX}

PORTDOCS=	${_DOCS:T}

OPTIONS_DEFINE=		DOCS LX PMENU
OPTIONS_DEFAULT=	LX PMENU
OPTIONS_SUB=		yes

LX_DESC=	Generate menu data for freedesktop defined application menus
PMENU_DESC=	Generate menu data based on desktop and directory files

LX_LIB_DEPENDS+=	libmenu-cache.so:x11/menu-cache
LX_CONFIGURE_ON=	--with-lx
PMENU_CONFIGURE_ON=	--with-pmenu

_LIBEXEC=	greeneye apps socket i18n obtheme config ob
_DOCS=		AUTHORS.md CONTRIBUTING.md INSTALL.md NEWS.md README.md TODO.md \
		docs/coding_style docs/default.csv docs/notes_on_icons \
		docs/relnotes/${DISTVERSION}.txt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLX}
_LIBEXEC+=	lx
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for f in ${_LIBEXEC}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/${PORTNAME}-${f}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${_DOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
