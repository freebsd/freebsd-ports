# Created by: Matthieu Guegan <matt.guegan@free.fr>
# $FreeBSD$

PORTNAME=	xmonad-contrib
PORTVERSION=	0.11.4
CATEGORIES=	x11-wm haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Third-party extensions for xmonad

LICENSE=	BSD3CLAUSE

USE_CABAL=	extensible-exceptions mtl>=1 old-time random utf8-string \
		X11>=1.6.1 xmonad>=0.11
USE_XORG=	x11

RUN_DEPENDS+=	bash:shells/bash

FLAGS_DEFINE=		XFT
FLAGS_DEFAULT=		XFT

XFT_DESC=		Use Xft to render text
XFT_FLAG_ENABLE=	use_xft
XFT_FLAG_CABAL=		X11-xft>=0.2

FLAGS_DISABLE=	testing

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
