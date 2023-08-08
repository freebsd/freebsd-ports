PORTNAME=	xmobar
PORTVERSION=	0.46
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Minimalistic text-based status bar
WWW=		https://xmobar.org/

LICENSE=	BSD3CLAUSE

USES=		cabal gnome pkgconfig xorg

USE_GNOME=	cairo pango

OPTIONS_DEFINE=		XFT XPM MPD INOTIFY DATEZONE THREADED UVMETER
OPTIONS_DEFAULT=	XFT

XFT_DESC=		Use Xft to render text (UTF-8 support included)
XFT_CABAL_FLAGS=	with_xft
XFT_USE_CABAL=		X11-xft-0.3.4
XFT_USE=		xorg=xft

XPM_DESC=		Use Xpm to render icons
XPM_CABAL_FLAGS=	with_xpm
XPM_USE=		xorg=xpm

MPD_DESC=		Music Player Daemon support
MPD_CABAL_FLAGS=	with_mpd
MPD_USE_CABAL=		libmpd-0.10.0.0 safe-exceptions-0.1.7.3

INOTIFY_DESC=		inotify support (required for the Mail and MBox plugins)
INOTIFY_CABAL_FLAGS=	with_inotify
INOTIFY_USE_CABAL=	hinotify-0.4.1
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify

DATEZONE_DESC=		Localized date support
DATEZONE_CABAL_FLAGS=	with_datezone
DATEZONE_USE_CABAL=	timezone-olson-0.2.1 timezone-series-0.1.13_1

THREADED_DESC=		Use threaded runtime
THREADED_CABAL_FLAGS=	with_threaded

UVMETER_DESC=		UV meter plugin
UVMETER_CABAL_FLAGS=	with_uvmeter

USE_XORG=	xrandr xrender xscrnsaver xinerama xext x11

USE_CABAL=	OneTuple-0.4.1.1 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		X11-1.10.3 \
		X11-xft-0.3.4 \
		aeson-2.1.2.1_3 \
		alex-3.2.7.4 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1 \
		async-2.2.4_3 \
		attoparsec-0.14.4_3 \
		base-compat-0.13.0 \
		base-compat-batteries-0.13.0 \
		base-orphans-0.9.0 \
		base64-bytestring-1.2.1.0 \
		basement-0.0.15 \
		bifunctors-5.6.1 \
		bitvec-1.1.4.0 \
		blaze-builder-0.4.2.2_1 \
		bsd-sysctl-1.0.8.0 \
		byteorder-1.0.4 \
		cairo-0.13.10.0 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.3 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		conduit-1.3.4.3_1 \
		conduit-extra-1.3.6 \
		connection-0.3.1_1 \
		contravariant-1.5.5 \
		cookie-0.4.6 \
		cryptonite-0.30 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.2_4 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		extensible-exceptions-0.1.1.4 \
		foldable1-classes-compat-0.1_2 \
		generically-0.1.1_1 \
		glib-0.13.10.0 \
		gtk2hs-buildtools-0.13.10.0 \
		happy-1.20.1.1 \
		hashable-1.4.2.0_1 \
		hashtables-1.3.1 \
		hourglass-0.2.12 \
		hsc2hs-0.68.9 \
		http-client-0.7.13.1_1 \
		http-client-tls-0.3.6.1 \
		http-conduit-2.3.8 \
		http-types-0.12.3 \
		indexed-traversable-0.1.2.1 \
		indexed-traversable-instances-0.1.1.2_1 \
		integer-logarithms-1.0.3.1_4 \
		iproute-1.7.12 \
		memory-0.18.0 \
		mime-types-0.1.1.0 \
		mono-traversable-1.0.15.3 \
		network-3.1.3.0 \
		network-uri-2.6.4.2 \
		old-locale-1.0.0.7_2 \
		pango-0.13.10.0 \
		parsec-numbers-0.1.0 \
		pem-0.2.4 \
		primitive-0.8.0.0 \
		random-1.2.1.1 \
		regex-base-0.94.0.2_1 \
		regex-compat-0.95.2.1_2 \
		regex-posix-0.96.0.1_1 \
		resourcet-1.3.0 \
		scientific-0.3.7.0_5 \
		semialign-1.3 \
		semigroupoids-6.0.0.1 \
		socks-0.6.1 \
		split-0.2.3.5 \
		splitmix-0.1.0.4_2 \
		streaming-commons-0.2.2.6 \
		strict-0.5 \
		tagged-0.8.7 \
		text-short-0.1.5_2 \
		th-abstraction-0.5.0.0 \
		th-compat-0.1.4_2 \
		these-1.2 \
		time-compat-1.9.6.1_5 \
		tls-1.6.0 \
		transformers-compat-0.7.2 \
		typed-process-0.2.11.0 \
		unliftio-core-0.2.1.0_2 \
		unordered-containers-0.2.19.1_2 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_4 \
		vector-0.13.0.0_3 \
		vector-algorithms-0.9.0.1_2 \
		vector-stream-0.1.0.0_2 \
		witherable-0.4.2_4 \
		x509-1.7.7 \
		x509-store-1.6.9 \
		x509-system-1.6.7 \
		x509-validation-1.6.12 \
		zlib-0.6.3.0_1

CABAL_FLAGS=		with_weather with_rtsopts with_utf8 \
			-with_mpris -with_dbus -with_iwlib -with_nl80211 -with_alsa -all_extensions

.include <bsd.port.mk>
