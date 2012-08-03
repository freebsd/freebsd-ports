# New ports collection makefile for:	xmonad
# Date created:		2007-10-25
# Whom:			Matthieu Guegan <matt.guegan@free.fr>
#
# $FreeBSD$
#

PORTNAME=	xmonad
PORTVERSION=	0.10
PORTREVISION=	3
CATEGORIES=	x11-wm haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Xmonad is a minimalist and tiling window manager for X

LICENSE=	BSD

USE_CABAL=	mtl utf8-string>=0.3 X11>=1.5.0.0
USE_XORG=	x11

MAN1=		xmonad.1
MAN1SRC=	man

EXECUTABLE=	xmonad

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
