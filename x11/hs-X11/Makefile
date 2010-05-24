# New ports collection makefile for:	hs-x11-ghc
# Date created:				2007-09-03
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	X11
PORTVERSION=	1.5.0.0
PORTREVISION=	1
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	X11 bindings for Haskell programs

CABAL_SETUP=	Setup.hs
USE_XORG=	x11 xext sm

OPTIONS=	XINERAMA "Build with Xinerama support" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_XINERAMA)
USE_XORG+=		xinerama
CONFIGURE_ARGS+=	--configure-option="--with-xinerama"
.else
CONFIGURE_ARGS+=	--configure-option="--without-xinerama"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
