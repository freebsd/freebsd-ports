# $FreeBSD$

PORTNAME=	X11-xft
PORTVERSION=	0.3.1
PORTREVISION=	21
CATEGORIES=	x11 haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Bindings to the Xft, Xrender and Freetype for Haskell programs

LICENSE=	LGPL21

IGNORE=		Haskell libraries are getting pushed out of the ports tree.

USES=		pkgconfig xorg
USE_CABAL=	utf8-string>=0.1 X11>=1.2.1
USE_XORG=	xft xrender

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
