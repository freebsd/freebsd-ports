# New ports collection makefile for:	xmonad-contrib
# Date created:		2008-01-23
# Whom:		Matthieu Guegan <matt.guegan@free.fr>
#
# $FreeBSD$
#

PORTNAME=	xmonad-contrib
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	x11-wm haskell
PKGNAMEPREFIX=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Third party tiling algorithms, configurations and scripts to xmonad

USE_HACKAGE=	xmonad utf8-string
USE_XORG=	x11

OPTIONS=	XFT "Enable Xft support for fonts" On

.include <bsd.port.pre.mk>

.if defined(WITH_XFT)
CONFIGURE_ARGS+=	--flags="use_xft"
USE_HACKAGE+=		X11-xft>=0.2
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.post.mk>
