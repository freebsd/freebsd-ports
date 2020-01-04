# Created by: Samy Al Bahra <sbahra@kerneled.org>
# $FreeBSD$

PORTNAME=	xmobar
PORTVERSION=	0.32
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Minimalistic text-based status bar

LICENSE=	BSD3CLAUSE

USES=		cabal pkgconfig xorg

OPTIONS_DEFINE=		EXAMPLES XFT XPM UTF8 MPD INOTIFY DATEZONE THREADED UVMETER
OPTIONS_DEFAULT=	XFT UTF8

XFT_DESC=		Use Xft to render text (UTF-8 support included)
XFT_CABAL_FLAGS=	with_xft
XFT_USE_CABAL=		utf8-string-1.0.1.1_3 X11-xft-0.3.1
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
MPD_USE_CABAL=		libmpd-0.9.0.10 safe-exceptions-0.1.7.0_5

INOTIFY_DESC=		inotify support (required for the Mail and MBox plugins)
INOTIFY_CABAL_FLAGS=	with_inotify
INOTIFY_USE_CABAL=	hinotify-0.4
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-hinotify.cabal

DATEZONE_DESC=		Localized date support
DATEZONE_CABAL_FLAGS=	with_datezone
DATEZONE_USE_CABAL=	timezone-olson-0.1.9 timezone-series-0.1.9

THREADED_DESC=		Use threaded runtime
THREADED_CABAL_FLAGS=	with_threaded

UVMETER_DESC=		UV meter plugin
UVMETER_CABAL_FLAGS=	with_uvmeter

USE_XORG=	xrandr xrender xscrnsaver xinerama xext x11

USE_CABAL=	X11-1.9.1 X11-xft-0.3.1 async-2.2.1_1 data-default-0.7.1.1 \
		data-default-class-0.1.2.0 data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 hashable-1.2.7.0_1 \
		data-default-instances-old-locale-0.0.1 dlist-0.8.0.5 \
		extensible-exceptions-0.1.1.4 old-locale-1.0.0.7_2 parsec-numbers-0.1.0 \
		random-1.1_1 regex-base-0.93.2 regex-compat-0.95.1 regex-posix-0.95.2 \
		utf8-string-1.0.1.1_3 http-types-0.12.3 case-insensitive-1.2.0.11 \
		http-conduit-2.3.6.1 unliftio-core-0.1.2.0_1 resourcet-1.2.2 \
		http-client-tls-0.3.5.3 tls-1.4.1 memory-0.14.18_1 \
		http-client-0.6.2 streaming-commons-0.2.1.0 mime-types-0.1.0.9 \
		exceptions-0.10.0_2 transformers-compat-0.6.2 cookie-0.4.4 \
		blaze-builder-0.4.1.0 cryptonite-0.25 basement-0.0.10_1 \
		connection-0.2.8_1 x509-validation-1.6.11 x509-system-1.6.6 \
		x509-store-1.6.7 x509-1.7.5 socks-0.5.6_1 byteable-0.1.1 \
		conduit-extra-1.3.1.1 typed-process-0.2.4.0 primitive-0.6.4.0_1 \
		conduit-1.3.1.1 vector-0.12.0.2 mono-traversable-1.0.11.0 \
		attoparsec-0.13.2.2_2 scientific-0.3.6.2 aeson-1.4.2.0 \
		uuid-types-1.0.3_1 unordered-containers-0.2.10.0 network-2.7.0.2_2 \
		network-uri-2.6.1.0_1 time-locale-compat-0.1.1.5 \
		th-abstraction-0.2.11.0 tagged-0.8.6 base-compat-0.10.5 \
		vector-algorithms-0.8.0.1 split-0.2.3.3_1 \
		integer-logarithms-1.0.2.2_1 cereal-0.5.8.0 asn1-types-0.3.2 \
		hourglass-0.2.12 asn1-encoding-0.9.5 pem-0.2.4 asn1-parse-0.9.4 \
		zlib-0.6.2

CABAL_FLAGS=		with_weather with_rtsopts \
			-with_mpris -with_dbus -with_iwlib -with_alsa -all_extensions

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/xmobar.config ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
