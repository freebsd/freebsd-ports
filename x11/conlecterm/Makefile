# $FreeBSD$

PORTNAME=	conlecterm
PORTVERSION=	1.4.1.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hsw@bitmark.com
COMMENT=	Multi tabbed terminal for rxvt/xterm/emacs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	urxvt:x11/rxvt-unicode

USES=		cabal xorg gnome pkgconfig
USE_GNOME=	gtk30 cairo glib20
USE_XORG=	xext x11 xscrnsaver xinerama xrandr

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	hxw

USE_CABAL=X11-1.9.1 \
	aeson-1.4.7.1_1 \
	alex-3.2.5 \
	attoparsec-0.13.2.4 \
	base-compat-0.11.1 \
	base-compat-batteries-0.11.1 \
	base-orphans-0.8.2 \
	cairo-0.13.8.0 \
	data-default-0.7.1.1 \
	data-default-class-0.1.2.0 \
	data-default-instances-containers-0.0.1 \
	data-default-instances-dlist-0.0.1 \
	data-default-instances-old-locale-0.0.1 \
	dlist-0.8.0.8 \
	glib-0.13.8.0 \
	gtk2hs-buildtools-0.13.8.0 \
	gtk3-0.15.4 \
	happy-1.19.12 \
	hashable-1.3.0.0_1 \
	hashtables-1.2.3.4 \
	integer-logarithms-1.0.3_2 \
	old-locale-1.0.0.7_2 \
	pango-0.13.8.0 \
	primitive-0.7.0.1 \
	random-1.1_1 \
	scientific-0.3.6.2 \
	tagged-0.8.6_2 \
	th-abstraction-0.3.2.0 \
	time-compat-1.9.3 \
	unordered-containers-0.2.10.0_1 \
	utf8-string-1.0.1.1_3 \
	uuid-types-1.0.3_2 \
	vector-0.12.1.2

PLIST_FILES+=	share/applications/conlecterm.desktop
PLIST_FILES+=	share/icons/hicolor/scalable/apps/conlecterm.svg

PORTEXAMPLES=	\
		conlecterm.conf \
		conlecterm.css \
		tabs.css

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/conlecterm.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/conlecterm.css ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tabs.css ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/conlecterm.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/conlecterm.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/

.include <bsd.port.mk>
