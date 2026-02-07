PORTNAME=	sterm
DISTVERSION=	0.9.3
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/st/
DISTNAME=	st-${DISTVERSION}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Simple X terminal
WWW=		https://st.suckless.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		pkgconfig xorg
USE_XORG=	x11 xext xft

MAKE_ARGS=	PREFIX="${PREFIX}" VERSION="${PORTVERSION}" \
		X11INC="${LOCALBASE}/include" X11LIB="${LOCALBASE}/lib"

# This way we avoid running tic on st.info which does not work as expected.
BINARY_ALIAS=	tic=true

PLIST_FILES=	bin/st share/man/man1/st.1.gz

PORTDATA=	config.def.h st.info
PORTDOCS=	FAQ LEGACY README TODO

OPTIONS_DEFINE=		DOCS SCROLLBACK XRESOURCES
SCROLLBACK_DESC=	Scroll back through terminal output
XRESOURCES_DESC=	Allow to handle settings from Xresources

SCROLLBACK_PATCH_SITES=	https://st.suckless.org/patches/scrollback/
SCROLLBACK_PATCHFILES=	st-scrollback-0.9.2.diff:-p1 \
			st-scrollback-mouse-0.9.2.diff:-p1

XRESOURCES_PATCH_SITES=	https://st.suckless.org/patches/xresources/
XRESOURCES_PATCHFILES=	st-xresources-20230320-45a15676.diff:-p1

pre-everything::
	@${ECHO_MSG} "You can build st with your own config.h using the ST_CONF knob:"
	@${ECHO_MSG} "make ST_CONF=/path/to/st/config.h install clean"

post-patch:
.if defined(ST_CONF)
	@${ECHO_MSG} "creating config.h from ${ST_CONF}"
	@${LN} -sf ${ST_CONF} ${WRKSRC}/config.h
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/st
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDATA} ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
