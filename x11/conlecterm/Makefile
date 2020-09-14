# $FreeBSD$

PORTNAME=	conlecterm
PORTVERSION=	1.4.3.0
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

USE_CABAL=	X11-1.9.1 \
		aeson-1.5.3.0 \
		alex-3.2.5 \
		assoc-1.0.2 \
		attoparsec-0.13.2.4 \
		base-compat-0.11.1 \
		base-compat-batteries-0.11.1 \
		base-orphans-0.8.2 \
		bifunctors-5.5.7 \
		cabal-doctest-1.0.8_1 \
		cairo-0.13.8.1 \
		comonad-5.0.6_1 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.0 \
		distributive-0.6.2_1 \
		dlist-1.0 \
		glib-0.13.8.1 \
		gtk2hs-buildtools-0.13.8.0 \
		gtk3-0.15.5 \
		happy-1.19.12 \
		hashable-1.3.0.0_1 \
		hashtables-1.2.3.4 \
		integer-logarithms-1.0.3_2 \
		old-locale-1.0.0.7_2 \
		pango-0.13.8.1 \
		primitive-0.7.1.0 \
		random-1.2.0 \
		scientific-0.3.6.2 \
		splitmix-0.1.0.1 \
		strict-0.4 \
		tagged-0.8.6_2 \
		th-abstraction-0.3.2.0 \
		these-1.1.1.1 \
		time-compat-1.9.3 \
		transformers-compat-0.6.5 \
		unordered-containers-0.2.12.0 \
		utf8-string-1.0.1.1_3 \
		uuid-types-1.0.3_3 \
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
