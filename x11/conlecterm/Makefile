PORTNAME=	conlecterm
PORTVERSION=	2.3.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	bsd.hsw@gmail.com
COMMENT=	Multi tabbed terminal for rxvt/xterm/emacs
WWW=		https://github.com/hxw/conlecterm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	urxvt:x11/rxvt-unicode

USES=		cabal xorg gnome pkgconfig desktop-file-utils
USE_GNOME=	gtk30 cairo glib20 gdkpixbuf introspection
USE_XORG=	xext x11 xscrnsaver xinerama xrandr

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	hxw

USE_CABAL=	OneTuple-0.4.2_1 \
		QuickCheck-2.16.0.0 \
		StateVar-1.2.2 \
		X11-1.10.3_1 \
		aeson-2.2.3.0_4 \
		ansi-terminal-1.1.5 \
		ansi-terminal-types-1.1.3 \
		assoc-1.1.1_1 \
		async-2.2.5_3 \
		attoparsec-0.14.4_6 \
		base-orphans-0.9.3 \
		bifunctors-5.6.2_2 \
		bitvec-1.1.5.0_3 \
		blaze-builder-0.4.4.1 \
		blaze-html-0.9.2.0_1 \
		blaze-markup-0.8.3.0_2 \
		cabal-doctest-1.0.12 \
		character-ps-0.1 \
		colour-2.3.6 \
		comonad-5.0.9_1 \
		conduit-1.3.6.1 \
		conduit-extra-1.3.8_1 \
		contravariant-1.5.5 \
		data-default-0.8.0.1 \
		data-default-class-0.2.0.0 \
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
		gi-gio-2.0.38 \
		gi-glib-2.0.30 \
		gi-gmodule-2.0.6 \
		gi-gobject-2.0.31 \
		gi-gtk-3.0.44_1 \
		gi-gtk3-3.0.44 \
		gi-harfbuzz-0.0.10 \
		gi-pango-1.0.30 \
		happy-2.1.7 \
		happy-lib-2.1.7 \
		hashable-1.5.0.0_1 \
		hashtables-1.4.2 \
		haskell-gi-0.26.17 \
		haskell-gi-base-0.26.9 \
		haskell-gi-overloading-1.0 \
		haskell-lexer-1.2.1 \
		hsc2hs-0.68.10_4 \
		indexed-profunctors-0.1.1.1 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		integer-conversion-0.1.1_1 \
		integer-logarithms-1.0.4 \
		mono-traversable-1.0.21.0 \
		network-3.2.8.0 \
		network-uri-2.6.4.2_1 \
		optics-core-0.4.1.1_1 \
		optparse-applicative-0.19.0.0 \
		os-string-2.0.8 \
		pretty-show-1.10 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0_1 \
		random-1.3.1 \
		regex-base-0.94.0.3 \
		regex-tdfa-1.3.2.5 \
		resourcet-1.3.0 \
		safe-0.3.21_1 \
		scientific-0.3.8.0_2 \
		semialign-1.3.1_2 \
		semigroupoids-6.0.1_2 \
		split-0.2.5 \
		splitmix-0.1.3.1 \
		streaming-commons-0.2.3.1 \
		strict-0.5.1_1 \
		tagged-0.8.10 \
		tasty-1.5.3_2 \
		text-iso8601-0.1.1_2 \
		text-short-0.1.6_3 \
		th-abstraction-0.7.1.0_1 \
		th-compat-0.1.6 \
		these-1.2.1_2 \
		time-compat-1.9.8 \
		transformers-compat-0.7.2 \
		typed-process-0.2.13.0 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.21_2 \
		uuid-types-1.0.6_3 \
		vector-0.13.2.0_2 \
		vector-algorithms-0.9.1.0 \
		vector-stream-0.1.0.1_4 \
		witherable-0.5_2 \
		xdg-basedir-0.2.2 \
		xml-conduit-1.10.1.0 \
		xml-types-0.3.8 \
		zlib-0.7.1.1

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
