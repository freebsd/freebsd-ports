# New ports collection makefile for:	xmobar
# Date created:				November 7, 2008
# Whom:					Samy Al Bahra <sbahra@kerneled.org>
#
# $FreeBSD$

PORTNAME=	xmobar
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A minimalistic text based status bar

LICENSE=	BSD

USE_CABAL=	mtl parsec stm X11>=1.3.0
USE_XORG=	x11 xrandr

EXECUTABLE=	xmobar
STANDALONE=	yes

INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/samples/xmobar.config ${DATADIR}

OPTIONS_DEFINE=		XFT UTF8 MPD
OPTIONS_DEFAULT=	UFT8

XFT_DESC=		Use Xft to render text (UTF-8 support included)
UTF8_DESC=		UTF-8 support
MPD_DESC=		mpd support

.include <bsd.port.options.mk>

# Disable Linux-only options
CONFIGURE_ARGS+=	--flags="-with_inotify -with_iwlib"

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

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
