# New ports collection makefile for:	hs-x11-xft-ghc
# Date created:		2008-10-21
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	x11-xft
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	x11 haskell
PKGNAMESUFFIX=	-ghc

MAINTAINER=	wahjava@gmail.com
COMMENT=	Bindings to the Xft, Xrender and Freetype for Haskell programs

USE_HACKAGE=	utf8-string>=0.1 X11>=1.2.1
USE_XORG=	xft xrender

MASTER_SITES=	http://hackage.haskell.org/packages/archive/X11-xft/${PORTVERSION}/
DISTNAME=	X11-xft-${PORTVERSION}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
