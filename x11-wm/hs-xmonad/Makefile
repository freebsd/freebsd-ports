# Created by: Matthieu Guegan <matt.guegan@free.fr>
# $FreeBSD$

PORTNAME=	xmonad
PORTVERSION=	0.11.1
CATEGORIES=	x11-wm haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tiling window manager

LICENSE=	BSD3CLAUSE

USE_CABAL=	extensible-exceptions mtl utf8-string>=0.3 X11>=1.5
USE_XORG=	x11

MAN1PAGES=	xmonad.1
MAN1SRC=	man

EXECUTABLE=	xmonad

OPTIONS_DEFINE+=	XFORK_FIX
OPTIONS_DEFAULT+=	XFORK_FIX

FLAGS_DISABLE=	testing

XFORK_FIX_DESC=		Apply workaround for losing hotkeys (XMonad \#576)

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"

.if ${PORT_OPTIONS:MXFORK_FIX}
EXTRA_PATCHES+=	${PATCHDIR}/nopatch-XMonad_Core.hs
.endif

.include <bsd.port.mk>
