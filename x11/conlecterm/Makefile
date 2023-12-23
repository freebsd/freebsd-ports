PORTNAME=	conlecterm
PORTVERSION=	1.4.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	hsw@bitmark.com
COMMENT=	Multi tabbed terminal for rxvt/xterm/emacs
WWW=		https://github.com/hxw/conlecterm

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

USE_CABAL=	OneTuple-0.4.1.1 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		X11-1.10.3 \
		aeson-2.1.2.1_3 \
		alex-3.2.7.4 \
		assoc-1.1 \
		attoparsec-0.14.4_3 \
		base-compat-0.13.0 \
		base-compat-batteries-0.13.0 \
		base-orphans-0.9.0 \
		bifunctors-5.6.1 \
		cairo-0.13.10.0 \
		comonad-5.0.8_1 \
		contravariant-1.5.5 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.2_4 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		foldable1-classes-compat-0.1_2 \
		generically-0.1.1_1 \
		gio-0.13.10.0 \
		glib-0.13.10.0 \
		gtk2hs-buildtools-0.13.10.0 \
		gtk3-0.15.8 \
		happy-1.20.1.1 \
		hashable-1.4.2.0_1 \
		hashtables-1.3.1 \
		indexed-traversable-0.1.2.1 \
		indexed-traversable-instances-0.1.1.2_1 \
		integer-logarithms-1.0.3.1_4 \
		pango-0.13.10.0 \
		primitive-0.8.0.0 \
		random-1.2.1.1 \
		scientific-0.3.7.0_5 \
		semialign-1.3 \
		semigroupoids-6.0.0.1 \
		splitmix-0.1.0.4_2 \
		strict-0.5 \
		tagged-0.8.7 \
		text-short-0.1.5_2 \
		th-abstraction-0.5.0.0 \
		these-1.2 \
		time-compat-1.9.6.1_5 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.19.1_2 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_4 \
		vector-0.13.0.0_3 \
		vector-stream-0.1.0.0_2 \
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
