# New ports collection makefile for:	xmobar
# Date created:				November 7, 2008
# Whom:					Samy Al Bahra <sbahra@kerneled.org>
#
# $FreeBSD$

PORTNAME=	xmobar
PORTVERSION=	0.11.1
CATEGORIES=	x11 haskell
PKGNAMEPREFIX=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A minimalistic text based status bar

USE_HACKAGE=	X11>=1.3.0
USE_XORG=	x11

EXECUTABLE=	xmobar
STANDALONE=	yes

PORTDATA=		*
INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/xmobar.config-sample ${DATADIR}

OPTIONS=	XFT   "Use Xft to render text (UTF-8 support included)" off \
		UTF8  "UTF-8 support" on \
		MPD   "mpd support" off

.include <bsd.port.options.mk>

# Disable Linux-only options
CONFIGURE_ARGS+=	--flags="-with_inotify -with_iwlib"

.if defined(WITH_XFT)
CONFIGURE_ARGS+=	--flags="with_xft"
USE_HACKAGE+=		utf8-string X11-xft>=0.2
.else
CONFIGURE_ARGS+=	--flags="-with_xft"
.endif

.if defined(WITH_UTF8)
CONFIGURE_ARGS+=	--flags="with_utf8"
.if !defined(WITH_XFT)
USE_HACKAGE+=		utf8-string
.endif
.else
CONFIGURE_ARGS+=	--flags="-with_utf8"
.endif

.if defined(WITH_MPD)
CONFIGURE_ARGS+=	--flags="with_mpd"
USE_HACKAGE+=		libmpd
.else
CONFIGURE_ARGS+=	--flags="-with_mpd"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
