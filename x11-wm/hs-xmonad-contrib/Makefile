# Created by: Matthieu Guegan <matt.guegan@free.fr>
# $FreeBSD$

PORTNAME=	xmonad-contrib
PORTVERSION=	0.13
PORTREVISION=	2
CATEGORIES=	x11-wm haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Third-party extensions for xmonad

LICENSE=	BSD3CLAUSE

USE_CABAL=	extensible-exceptions mtl>=1 old-time random utf8-string \
		X11>=1.6.1 X11-xft>=0.2 xmonad==0.13_2
USE_XORG=	x11

RUN_DEPENDS+=	bash:shells/bash

FLAGS_DISABLE=	testing

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
