# New ports collection makefile for:	xmonad-contrib
# Date created:		2008-01-23
# Whom:		Matthieu Guegan <matt.guegan@free.fr>
#
# $FreeBSD$
#

PORTNAME=	xmonad-contrib
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	x11-wm haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Third party tiling algorithms, configurations and scripts to xmonad

LICENSE=	BSD

USE_CABAL=	mtl xmonad>=0.9.1 X11>=1.5 utf8-string
USE_XORG=	x11

OPTIONS=	XFT "Enable Xft support for fonts" On

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_XFT)
CONFIGURE_ARGS+=	--flags="use_xft"
USE_CABAL+=		X11-xft>=0.2
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
