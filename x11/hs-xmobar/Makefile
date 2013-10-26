# Created by: Samy Al Bahra <sbahra@kerneled.org>
# $FreeBSD$

PORTNAME=	xmobar
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Minimalistic text-based status bar

LICENSE=	BSD

USE_CABAL=	mtl>=2.0 parsec stm>=2.3 X11>=1.6.1
USE_XORG=	xrandr

EXECUTABLE=	xmobar
STANDALONE=	yes

INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/samples/xmobar.config ${DATADIR}

OPTIONS_DEFINE=		XFT UTF8 MPD INOTIFY DATEZONE THREADED
OPTIONS_DEFAULT=	UTF8

XFT_DESC=		Use Xft to render text (UTF-8 support included)
UTF8_DESC=		UTF-8 support
MPD_DESC=		mpd support
INOTIFY_DESC=		inotify support
DATEZONE_DESC=		Localized date support
THREADED_DESC=		Use threaded runtime

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

# Disable unsupported options
CONFIGURE_ARGS+=	--flags="-with_iwlib -with_dbus -with_mpris"

.if ${PORT_OPTIONS:MXFT}
CONFIGURE_ARGS+=	--flags="with_xft"
USE_CABAL+=		utf8-string X11-xft>=0.2
.else
CONFIGURE_ARGS+=	--flags="-with_xft"
.endif

.if ${PORT_OPTIONS:MUTF8}
CONFIGURE_ARGS+=	--flags="with_utf8"
.if empty(PORT_OPTIONS:MXFT)
USE_CABAL+=		utf8-string
.endif
.else
CONFIGURE_ARGS+=	--flags="-with_utf8"
.endif

.if ${PORT_OPTIONS:MMPD}
CONFIGURE_ARGS+=	--flags="with_mpd"
USE_CABAL+=		libmpd
.else
CONFIGURE_ARGS+=	--flags="-with_mpd"
.endif

.if ${PORT_OPTIONS:MINOTIFY}
CONFIGURE_ARGS+=	--flags="with_inotify"
USE_CABAL+=		hinotify>=0.3
.else
CONFIGURE_ARGS+=	--flags="-with_inotify"
.endif

.if ${PORT_OPTIONS:MDATEZONE}
CONFIGURE_ARGS+=	--flags="with_datezone"
USE_CABAL+=		timezone-olson>=0.1 timezone-series>=0.1
.else
CONFIGURE_ARGS+=	--flags="-with_datezone"
.endif

.if ${PORT_OPTIONS:MTHREADED}
CONFIGURE_ARGS+=	--flags="with_threaded"
.else
CONFIGURE_ARGS+=	--flags="-with_threaded"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
