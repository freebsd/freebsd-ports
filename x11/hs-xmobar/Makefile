PORTNAME=	xmobar
PORTVERSION=	0.48
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Minimalistic text-based status bar
WWW=		https://xmobar.org/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		cabal gnome pkgconfig xorg

USE_GNOME=	cairo pango

OPTIONS_DEFINE=		XPM MPD INOTIFY DATEZONE THREADED UVMETER

XPM_DESC=		Use Xpm to render icons
XPM_CABAL_FLAGS=	with_xpm
XPM_USE=		xorg=xpm

MPD_DESC=		Music Player Daemon support
MPD_CABAL_FLAGS=	with_mpd
MPD_USE_CABAL=		libmpd-0.10.0.0 safe-exceptions-0.1.7.4_1

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

USE_XORG=	xrandr xrender xscrnsaver xinerama xext xft x11

USE_CABAL=	OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		X11-1.10.3 \
		X11-xft-0.3.4 \
		aeson-2.2.1.0_1 \
		alex-3.5.1.0 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.1_1 \
		async-2.2.5 \
		attoparsec-0.14.4_5 \
		attoparsec-aeson-2.2.0.1 \
		base-orphans-0.9.1 \
		base16-bytestring-1.0.2.0_1 \
		base64-bytestring-1.2.1.0_1 \
		basement-0.0.16 \
		bifunctors-5.6.2 \
		bitvec-1.1.5.0_1 \
		blaze-builder-0.4.2.3 \
		bsd-sysctl-1.0.8.0 \
		byteorder-1.0.4 \
		cairo-0.13.10.0_2 \
		case-insensitive-1.2.1.0 \
		cborg-0.2.10.0 \
		cereal-0.5.8.3 \
		clock-0.8.4 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		conduit-1.3.5 \
		conduit-extra-1.3.6 \
		contravariant-1.5.5 \
		cookie-0.5.0 \
		crypton-0.34 \
		crypton-connection-0.3.2 \
		crypton-x509-1.7.6_1 \
		crypton-x509-store-1.6.9 \
		crypton-x509-system-1.6.7 \
		crypton-x509-validation-1.6.12 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.2_5 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		extensible-exceptions-0.1.1.4 \
		extra-1.7.14 \
		generically-0.1.1_2 \
		glib-0.13.10.0_2 \
		gtk2hs-buildtools-0.13.10.0_1 \
		half-0.3.1_1 \
		happy-1.20.1.1 \
		hashable-1.4.4.0_1 \
		hashtables-1.3.1 \
		hourglass-0.2.12 \
		hsc2hs-0.68.10_2 \
		http-client-0.7.17 \
		http-client-tls-0.3.6.3 \
		http-conduit-2.3.8.3 \
		http-types-0.12.4 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-conversion-0.1.0.1_1 \
		integer-logarithms-1.0.3.1_6 \
		iproute-1.7.12 \
		memory-0.18.0 \
		mime-types-0.1.2.0 \
		mono-traversable-1.0.17.0 \
		network-3.1.4.0_1 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.4 \
		os-string-2.0.2 \
		pango-0.13.10.0_2 \
		parsec-numbers-0.1.0 \
		pem-0.2.4 \
		primitive-0.9.0.0_1 \
		random-1.2.1.2 \
		regex-base-0.94.0.2_4 \
		regex-compat-0.95.2.1_2 \
		regex-posix-0.96.0.1_3 \
		resourcet-1.3.0 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		serialise-0.2.6.1_1 \
		socks-0.6.1 \
		split-0.2.5 \
		splitmix-0.1.0.5_1 \
		streaming-commons-0.2.2.6_1 \
		strict-0.5_1 \
		tagged-0.8.8_1 \
		text-iso8601-0.1_1 \
		text-short-0.1.5_3 \
		th-abstraction-0.6.0.0_2 \
		th-compat-0.1.5 \
		these-1.2_1 \
		time-compat-1.9.6.1_6 \
		tls-2.0.2 \
		transformers-compat-0.7.2 \
		typed-process-0.2.11.1 \
		unix-time-0.4.12 \
		unliftio-core-0.2.1.0_3 \
		unordered-containers-0.2.20_1 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0_1 \
		vector-algorithms-0.9.0.1_3 \
		vector-stream-0.1.0.1_1 \
		witherable-0.4.2_4 \
		zlib-0.7.0.0_1

CABAL_FLAGS=		with_weather with_rtsopts with_utf8 \
			-with_mpris -with_dbus -with_iwlib -with_nl80211 -with_alsa -all_extensions

.include <bsd.port.mk>
