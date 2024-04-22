PORTNAME=	conlecterm
PORTVERSION=	1.5.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	hsw@bitmark.com
COMMENT=	Multi tabbed terminal for rxvt/xterm/emacs
WWW=		https://github.com/hxw/conlecterm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	urxvt:x11/rxvt-unicode

USES=		cabal xorg gnome pkgconfig
USE_GNOME=	gtk30 cairo glib20 gdkpixbuf2
USE_XORG=	xext x11 xscrnsaver xinerama xrandr

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	hxw

USE_CABAL=	OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		X11-1.10.3 \
		aeson-2.2.1.0_1 \
		alex-3.5.1.0 \
		assoc-1.1_1 \
		base-orphans-0.9.1 \
		bifunctors-5.6.1_3 \
		cairo-0.13.10.0_2 \
		comonad-5.0.8_2 \
		contravariant-1.5.5 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.2_5 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		generically-0.1.1_2 \
		gio-0.13.10.0_1 \
		glib-0.13.10.0_2 \
		gtk2hs-buildtools-0.13.10.0_1 \
		gtk3-0.15.8 \
		happy-1.20.1.1 \
		hashable-1.4.3.0_1 \
		hashtables-1.3.1 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-conversion-0.1.0.1_1 \
		integer-logarithms-1.0.3.1_5 \
		network-uri-2.6.4.2_1 \
		pango-0.13.10.0_2 \
		primitive-0.9.0.0_1 \
		random-1.2.1.2 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		splitmix-0.1.0.5 \
		strict-0.5_1 \
		tagged-0.8.8_1 \
		text-iso8601-0.1_1 \
		text-short-0.1.5_3 \
		th-abstraction-0.6.0.0_2 \
		th-compat-0.1.4_4 \
		these-1.2_1 \
		time-compat-1.9.6.1_6 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.20_1 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0_1 \
		vector-stream-0.1.0.1_1 \
		witherable-0.4.2_4

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
