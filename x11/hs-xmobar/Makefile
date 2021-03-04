# Created by: Samy Al Bahra <sbahra@kerneled.org>
# $FreeBSD$

PORTNAME=	xmobar
PORTVERSION=	0.37
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Minimalistic text-based status bar

LICENSE=	BSD3CLAUSE

USES=		cabal pkgconfig xorg

OPTIONS_DEFINE=		EXAMPLES XFT XPM UTF8 MPD INOTIFY DATEZONE THREADED UVMETER
OPTIONS_DEFAULT=	XFT UTF8

XFT_DESC=		Use Xft to render text (UTF-8 support included)
XFT_CABAL_FLAGS=	with_xft
XFT_USE_CABAL=		X11-xft-0.3.1
XFT_USE=		xorg=xft
XFT_IMPLIES=		UTF8

XPM_DESC=		Use Xpm to render icons
XPM_CABAL_FLAGS=	with_xpm
XPM_USE=		xorg=xpm

UTF8_DESC=		UTF-8 support
UTF8_CABAL_FLAGS=	with_utf8
UTF8_USE_CABAL=		utf8-string-1.0.1.1_3

MPD_DESC=		Music Player Daemon support
MPD_CABAL_FLAGS=	with_mpd
MPD_USE_CABAL=		libmpd-0.10.0.0 safe-exceptions-0.1.7.0_6

INOTIFY_DESC=		inotify support (required for the Mail and MBox plugins)
INOTIFY_CABAL_FLAGS=	with_inotify
INOTIFY_USE_CABAL=	hinotify-0.4.1
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify

DATEZONE_DESC=		Localized date support
DATEZONE_CABAL_FLAGS=	with_datezone
DATEZONE_USE_CABAL=	timezone-olson-0.2.0 timezone-series-0.1.9

THREADED_DESC=		Use threaded runtime
THREADED_CABAL_FLAGS=	with_threaded

UVMETER_DESC=		UV meter plugin
UVMETER_CABAL_FLAGS=	with_uvmeter

USE_XORG=	xrandr xrender xscrnsaver xinerama xext x11

USE_CABAL=	X11-1.9.2 \
		aeson-1.5.4.1 \
		asn1-encoding-0.9.6_1 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.0.2 \
		async-2.2.2_1 \
		attoparsec-0.13.2.4_1 \
		base-compat-0.11.2 \
		base-compat-batteries-0.11.2 \
		base-orphans-0.8.3 \
		basement-0.0.11_2 \
		bifunctors-5.5.8 \
		blaze-builder-0.4.1.0_1 \
		bsd-sysctl-1.0.8.0 \
		cabal-doctest-1.0.8_2 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.1 \
		comonad-5.0.6_1 \
		conduit-1.3.3 \
		conduit-extra-1.3.5 \
		connection-0.3.1_1 \
		cookie-0.4.5 \
		cryptonite-0.27 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.0 \
		distributive-0.6.2_2 \
		dlist-1.0 \
		extensible-exceptions-0.1.1.4 \
		hashable-1.3.0.0_1 \
		hourglass-0.2.12 \
		hsc2hs-0.68.7 \
		http-client-0.7.2.1 \
		http-client-tls-0.3.5.3_1 \
		http-conduit-2.3.7.3_1 \
		http-types-0.12.3 \
		integer-logarithms-1.0.3_2 \
		memory-0.15.0_1 \
		mime-types-0.1.0.9 \
		mono-traversable-1.0.15.1 \
		network-3.1.2.0_1 \
		network-uri-2.6.3.0 \
		old-locale-1.0.0.7_2 \
		parsec-numbers-0.1.0 \
		pem-0.2.4 \
		primitive-0.7.1.0 \
		random-1.2.0_2 \
		regex-base-0.94.0.0_1 \
		regex-compat-0.95.2.0_1 \
		regex-posix-0.96.0.0_1 \
		resourcet-1.2.4.2 \
		scientific-0.3.6.2 \
		socks-0.6.1 \
		split-0.2.3.4 \
		splitmix-0.1.0.3 \
		streaming-commons-0.2.2.1 \
		strict-0.4 \
		tagged-0.8.6_3 \
		th-abstraction-0.4.0.0 \
		these-1.1.1.1 \
		time-compat-1.9.3 \
		tls-1.5.4 \
		transformers-compat-0.6.6 \
		typed-process-0.2.6.0 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.13.0 \
		uuid-types-1.0.3_3 \
		vector-0.12.1.2 \
		vector-algorithms-0.8.0.3 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		zlib-0.6.2.2

CABAL_FLAGS=		with_weather with_rtsopts \
			-with_mpris -with_dbus -with_iwlib -with_nl80211 -with_alsa -all_extensions

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/xmobar.config ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
