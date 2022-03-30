PORTNAME=	conlecterm
PORTVERSION=	1.4.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	x11

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

INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	hxw

USE_CABAL=	OneTuple-0.3.1_2 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		X11-1.10.2 \
		aeson-2.0.3.0 \
		alex-3.2.7.1 \
		assoc-1.0.2_2 \
		attoparsec-0.14.4_1 \
		base-compat-0.12.1 \
		base-compat-batteries-0.12.1_2 \
		base-orphans-0.8.6 \
		bifunctors-5.5.11_1 \
		cairo-0.13.8.2 \
		comonad-5.0.8_1 \
		contravariant-1.5.5 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.2_2 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		gio-0.13.8.2 \
		glib-0.13.8.2 \
		gtk2hs-buildtools-0.13.8.3 \
		gtk3-0.15.7 \
		happy-1.20.0 \
		hashable-1.4.0.2 \
		hashtables-1.3 \
		indexed-traversable-0.1.2_1 \
		indexed-traversable-instances-0.1.1 \
		integer-logarithms-1.0.3.1_2 \
		pango-0.13.8.2 \
		primitive-0.7.3.0 \
		random-1.2.1 \
		scientific-0.3.7.0_2 \
		semialign-1.2.0.1_1 \
		semigroupoids-5.3.7 \
		splitmix-0.1.0.4 \
		strict-0.4.0.1_4 \
		tagged-0.8.6.1_2 \
		text-short-0.1.5 \
		th-abstraction-0.4.3.0 \
		these-1.1.1.1_5 \
		time-compat-1.9.6.1_3 \
		transformers-compat-0.7.1_1 \
		unordered-containers-0.2.17.0 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_2 \
		vector-0.12.3.1_1 \
		witherable-0.4.2_2

PLIST_FILES+=	share/applications/conlecterm.desktop
PLIST_FILES+=	share/icons/hicolor/scalable/apps/conlecterm.svg

PORTEXAMPLES=	conlecterm.conf \
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
