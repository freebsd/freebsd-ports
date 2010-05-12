# New ports collection makefile for:	xmobar
# Date created:				November 7, 2008
# Whom:					Samy Al Bahra <sbahra@kerneled.org>
#
# $FreeBSD$

PORTNAME=	xmobar
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	x11 haskell
PKGNAMEPREFIX=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A minimalistic text based status bar

USE_HACKAGE=	X11>=1.3.0
USE_XORG=	x11

EXECUTABLE=	xmobar
STANDALONE=	yes

PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	${INSTALL_DATA} ${WRKSRC}/xmobar.config-sample ${EXAMPLESDIR}

OPTIONS=	XFT "Enable Xft support for fonts" Off	\
		UTF8 "Enable UTF-8 support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_XFT)
CONFIGURE_ARGS+=	--flags="with_xft"
USE_HACKAGE+=		X11-xft>=0.2
.elif defined(WITH_UTF8)
CONFIGURE_ARGS+=	--flags="with_utf8"
USE_HACKAGE+=		utf8-string
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.post.mk>
