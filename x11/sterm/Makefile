# Created by: Matthew Donovan <kitchetech@gmail.com>
# $FreeBSD$

PORTNAME=	sterm
DISTVERSION=	0.8.2
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/st/
DISTNAME=	st-${PORTVERSION}

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Simple X terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		pkgconfig xorg
USE_XORG=	x11 xext xft

PLIST_FILES=	bin/st man/man1/st.1.gz

# This way we avoid running tic on st.info which does not work as expected.
BINARY_ALIAS=	tic=true

PORTDATA=	config.def.h st.info
PORTDOCS=	FAQ LEGACY README TODO

OPTIONS_DEFINE=	DOCS
OPTIONS_RADIO=	PATCHES
OPTIONS_RADIO_PATCHES=	SCROLLBACK SOLARIZED
SCROLLBACK_DESC=	Scroll back through terminal output
SOLARIZED_DESC=	Use Solarized color scheme

SCROLLBACK_EXTRA_PATCHES=	${PATCHDIR}/extra-scrollback-patch-config.def.h \
		${PATCHDIR}/extra-scrollback-patch-st.c \
		${PATCHDIR}/extra-scrollback-patch-st.h

SOLARIZED_EXTRA_PATCHES=	${PATCHDIR}/extra-solarized-patch-config.def.h \
		${PATCHDIR}/extra-solarized-patch-x.c \
		${PATCHDIR}/extra-solarized-patch-st.h

pre-everything::
	@${ECHO_MSG} "You can build st with your own config.h using the ST_CONF knob:"
	@${ECHO_MSG} "make ST_CONF=/path/to/st/config.h install clean"

post-patch:
.if defined(ST_CONF)
	@${ECHO_MSG} "creating config.h from ${ST_CONF}"
	@${LN} -sf ${ST_CONF} ${WRKSRC}/config.h
.endif
	@${REINPLACE_CMD} -e 's|^VERSION = .*|VERSION = ${PORTVERSION}|' \
		-e 's|^PREFIX = .*|PREFIX = ${PREFIX}|' \
		-e "s|^MANPREFIX = .*|MANPREFIX = ${MANPREFIX}/man|" \
		-e "s|^X11INC = .*|X11INC = ${LOCALBASE}/include|" \
		-e "s|^X11LIB = .*|X11LIB = ${LOCALBASE}/lib|" \
		-e "s|^CPPFLAGS =|CPPFLAGS +=|" \
		${WRKSRC}/config.mk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/st
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDATA} ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
