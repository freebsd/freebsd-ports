# Created by: Matthieu Guegan <matt.guegan@free.fr>
# $FreeBSD$

PORTNAME=	xmonad
PORTVERSION=	0.13
PORTREVISION=	3
CATEGORIES=	x11-wm haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tiling window manager

LICENSE=	BSD3CLAUSE

USE_CABAL=	extensible-exceptions mtl semigroups setlocale utf8-string X11
USE_XORG=	x11

MAN1PAGES=	xmonad.1
MAN1SRC=	man

EXECUTABLE=	xmonad

FLAGS_DISABLE=	testing

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"

.include <bsd.port.mk>
