# Created by: Matthieu Guegan <matt.guegan@free.fr>
# $FreeBSD$

PORTNAME=	xmonad-contrib
PORTVERSION=	0.11.1
PORTREVISION=	5
CATEGORIES=	x11-wm haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Third-party extensions for xmonad

LICENSE=	BSD

USE_CABAL=	mtl random utf8-string X11>=1.6 xmonad>=0.11
USE_XORG=	x11

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

OPTIONS_DEFINE=		XFT
OPTIONS_DEFAULT=	XFT

XFT_DESC=		Use Xft to render text

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MXFT}
CONFIGURE_ARGS+=	--flags="use_xft"
USE_CABAL+=		X11-xft>=0.2
.else
CONFIGURE_ARGS+=	--flags="-use_xft"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
