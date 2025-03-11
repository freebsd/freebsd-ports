PORTNAME=	conlecterm
PORTVERSION=	2.2.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	bsd.hsw@gmail.com
COMMENT=	Multi tabbed terminal for rxvt/xterm/emacs
WWW=		https://github.com/hxw/conlecterm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	urxvt:x11/rxvt-unicode

USES=		cabal xorg gnome pkgconfig desktop-file-utils
USE_GNOME=	gtk30 cairo glib20 gdkpixbuf
USE_XORG=	xext x11 xscrnsaver xinerama xrandr

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	hxw

USE_CABAL=	OneTuple-0.4.2_1 \
		QuickCheck-2.15.0.1 \
		StateVar-1.2.2 \
		X11-1.10.3 \
		aeson-2.2.3.0_3 \
		ansi-terminal-1.1.2 \
		ansi-terminal-types-1.1 \
		assoc-1.1.1_1 \
		async-2.2.5_3 \
		attoparsec-0.14.4_6 \
		base-orphans-0.9.3 \
		bifunctors-5.6.2_1 \
		bitvec-1.1.5.0_3 \
		blaze-builder-0.4.2.3 \
		blaze-html-0.9.2.0_1 \
		blaze-markup-0.8.3.0_2 \
		cabal-doctest-1.0.11 \
		character-ps-0.1 \
		colour-2.3.6 \
		comonad-5.0.9 \
		conduit-1.3.6 \
		conduit-extra-1.3.7 \
		contravariant-1.5.5 \
		data-default-0.8.0.0 \
		data-default-class-0.1.2.2 \
		data-fix-0.3.4_1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		generically-0.1.1_4 \
		gi-atk-2.0.28 \
		gi-cairo-1.0.30 \
		gi-freetype2-2.0.5 \
		gi-gdk-3.0.30_1 \
		gi-gdk3-3.0.30 \
		gi-gdkpixbuf-2.0.32 \
		gi-gio-2.0.35 \
		gi-glib-2.0.30 \
		gi-gmodule-2.0.6 \
		gi-gobject-2.0.31 \
		gi-gtk-3.0.43 \
		gi-harfbuzz-0.0.10 \
		gi-pango-1.0.30 \
		happy-2.1.4 \
		happy-lib-2.1.4 \
		hashable-1.5.0.0_1 \
		hashtables-1.4.2 \
		haskell-gi-0.26.14 \
		haskell-gi-base-0.26.8 \
		haskell-gi-overloading-1.0 \
		haskell-lexer-1.1.2 \
		hsc2hs-0.68.10_3 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		integer-conversion-0.1.1_1 \
		integer-logarithms-1.0.4 \
		mono-traversable-1.0.21.0 \
		network-3.2.7.0 \
		network-uri-2.6.4.2_1 \
		optparse-applicative-0.18.1.0_1 \
		os-string-2.0.7 \
		pretty-show-1.10 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.0.0_2 \
		random-1.2.1.3 \
		regex-base-0.94.0.2_4 \
		regex-tdfa-1.3.2.2_3 \
		resourcet-1.3.0 \
		safe-0.3.21_1 \
		scientific-0.3.8.0_2 \
		semialign-1.3.1_2 \
		semigroupoids-6.0.1_1 \
		split-0.2.5 \
		splitmix-0.1.1 \
		streaming-commons-0.2.3.0 \
		strict-0.5.1_1 \
		tagged-0.8.9 \
		tasty-1.5.3 \
		text-iso8601-0.1.1_2 \
		text-short-0.1.6_3 \
		th-abstraction-0.7.1.0 \
		th-compat-0.1.6 \
		these-1.2.1_2 \
		time-compat-1.9.8 \
		transformers-compat-0.7.2 \
		typed-process-0.2.12.0 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.20_4 \
		uuid-types-1.0.6_2 \
		vector-0.13.2.0_1 \
		vector-algorithms-0.9.1.0 \
		vector-stream-0.1.0.1_3 \
		witherable-0.5_1 \
		xdg-basedir-0.2.2 \
		xml-conduit-1.10.0.0 \
		xml-types-0.3.8 \
		zlib-0.7.1.0_2

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
