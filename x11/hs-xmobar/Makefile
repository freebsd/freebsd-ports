PORTNAME=	xmobar
DISTVERSION=	0.51.1
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Minimalistic text-based status bar
WWW=		https://xmobar.org/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libpng16.so:graphics/png

USES=		cabal gnome pkgconfig xorg

USE_GNOME=	cairo pango
USE_XORG=	x11 xext xft xinerama xrandr xrender xscrnsaver
USE_CABAL=	OneTuple-0.4.3 \
		QuickCheck-2.18.0.0 \
		StateVar-1.2.2 \
		X11-1.10.3_1 \
		X11-xft-0.3.4 \
		aeson-2.3.1.0 \
		alex-3.5.4.2 \
		ansi-terminal-1.1.5 \
		ansi-terminal-types-1.1.3 \
		appar-0.1.8 \
		assoc-1.1.1_2 \
		async-2.2.6 \
		attoparsec-0.14.4_6 \
		attoparsec-aeson-2.2.2.0_1 \
		base-orphans-0.9.4 \
		base16-1.0_4 \
		base16-bytestring-1.0.2.0_1 \
		base64-1.0_3 \
		base64-bytestring-1.2.1.0_1 \
		bifunctors-5.6.3_1 \
		bitvec-1.1.6.0 \
		blaze-builder-0.4.4.1 \
		bsd-sysctl-1.0.8.0 \
		byteorder-1.0.4 \
		cairo-0.13.12.0 \
		case-insensitive-1.2.1.0 \
		cborg-0.2.10.0_3 \
		cereal-0.5.8.3 \
		character-ps-0.1 \
		clock-0.8.4 \
		colour-2.3.7 \
		comonad-5.0.10 \
		conduit-1.3.6.1 \
		conduit-extra-1.3.8_1 \
		contravariant-1.5.6 \
		cookie-0.5.1 \
		cryptohash-md5-0.11.101.0_6 \
		crypton-1.1.4 \
		crypton-asn1-encoding-0.10.0 \
		crypton-asn1-parse-0.10.0 \
		crypton-asn1-types-0.4.1 \
		crypton-connection-0.4.6_1 \
		crypton-pem-0.3.0 \
		crypton-socks-0.6.2 \
		crypton-x509-1.9.1 \
		crypton-x509-store-1.9.0 \
		crypton-x509-system-1.9.0 \
		crypton-x509-validation-1.9.1_1 \
		data-default-0.8.0.2 \
		data-default-class-0.2.0.0 \
		data-fix-0.3.4_2 \
		distributive-0.6.3 \
		dlist-1.0_2 \
		ech-config-0.0.1_1 \
		extra-1.8.1 \
		glib-0.13.12.0 \
		gtk2hs-buildtools-0.13.12.0 \
		half-0.3.3_2 \
		happy-2.2 \
		happy-lib-2.2 \
		hashable-1.5.1.0 \
		hashtables-1.4.2 \
		hpke-0.1.0 \
		hsc2hs-0.68.10_5 \
		http-client-0.7.19 \
		http-client-tls-0.4.0 \
		http-conduit-2.3.9.1_1 \
		http-types-0.12.5 \
		indexed-traversable-0.1.5 \
		indexed-traversable-instances-0.1.2.1 \
		integer-conversion-0.1.1_2 \
		integer-logarithms-1.0.5 \
		iproute-1.7.15 \
		mime-types-0.1.2.2 \
		mlkem-0.2.2.0 \
		mono-traversable-1.0.21.0 \
		network-3.2.8.0 \
		network-byte-order-0.1.8 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		optparse-applicative-0.19.0.0_1 \
		pango-0.13.12.0 \
		parsec-numbers-0.1.0 \
		prettyprinter-1.7.2 \
		prettyprinter-ansi-terminal-1.1.4 \
		primitive-0.9.1.0_1 \
		ram-0.22.0 \
		random-1.3.1 \
		regex-base-0.94.0.3 \
		regex-compat-0.95.2.2 \
		regex-posix-0.96.0.2 \
		resourcet-1.3.0 \
		scientific-0.3.8.1 \
		semialign-1.4 \
		semigroupoids-6.0.2_1 \
		serialise-0.2.6.1_5 \
		split-0.2.5 \
		splitmix-0.1.3.2 \
		streaming-commons-0.2.3.1 \
		strict-0.5.1_1 \
		tagged-0.8.10_1 \
		tasty-1.5.4 \
		text-iso8601-0.2.0.0 \
		text-short-0.1.6.1 \
		th-abstraction-0.7.2.0 \
		th-compat-0.1.7 \
		these-1.2.1_3 \
		time-compat-1.9.9_1 \
		time-hourglass-0.3.0 \
		tls-2.4.3 \
		transformers-compat-0.8 \
		typed-process-0.2.13.0 \
		unix-time-0.5.0 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.21_2 \
		utf8-string-1.0.2 \
		uuid-types-1.0.6.1 \
		vector-0.13.2.0_5 \
		vector-algorithms-0.9.1.0_1 \
		vector-stream-0.1.0.1_4 \
		witherable-0.5_2 \
		zlib-0.7.1.1

CABAL_FLAGS=		with_weather with_rtsopts with_utf8 \
			-with_mpris -with_dbus -with_iwlib  \
			-with_nl80211 -with_alsa -all_extensions

OPTIONS_DEFINE=		XPM MPD INOTIFY DATEZONE THREADED UVMETER

XPM_DESC=		Use Xpm to render icons
XPM_CABAL_FLAGS=	with_xpm
XPM_USE=		xorg=xpm

MPD_DESC=		Music Player Daemon support
MPD_CABAL_FLAGS=	with_mpd
MPD_USE_CABAL=		libmpd-0.10.0.1 safe-exceptions-0.1.7.4_1

INOTIFY_DESC=		inotify support (required for the Mail and MBox plugins)
INOTIFY_CABAL_FLAGS=	with_inotify
INOTIFY_USE_CABAL=	hinotify-0.4.2
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify

DATEZONE_DESC=		Localized date support
DATEZONE_CABAL_FLAGS=	with_datezone
DATEZONE_USE_CABAL=	extensible-exceptions-0.1.1.4 timezone-olson-0.2.1_1 \
			timezone-series-0.1.13_2

THREADED_DESC=		Use threaded runtime
THREADED_CABAL_FLAGS=	with_threaded

UVMETER_DESC=		UV meter plugin
UVMETER_CABAL_FLAGS=	with_uvmeter

.include <bsd.port.mk>
