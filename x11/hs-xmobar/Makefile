# New ports collection makefile for:	xmobar
# Date created:				November 7, 2008
# Whom:					Samy Al Bahra <sbahra@kerneled.org>
#
# $FreeBSD$

PORTNAME=	xmobar
PORTVERSION=	0.9
CATEGORIES=	x11 haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/xmobar/${PORTVERSION}/ \
		http://carte.kerneled.org/mirror/

MAINTAINER=	sbahra@kerneled.org
COMMENT=	Xmobar is a minimalistic text based status bar

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-x11-ghc>=1.4.1:${PORTSDIR}/x11/hs-x11-ghc
LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4

USE_XORG=	x11

CABAL=		${LOCALBASE}/bin/runghc Setup.lhs
GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
SUBDIR=		lib/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	GHC_VERSION="${GHC_VERSION}"		\
		PORTVERSION=${PORTVERSION}		\
		SUBDIR=${SUBDIR}

do-configure:
	cd ${WRKSRC} && ${CABAL} configure --prefix=${PREFIX} --ghc

do-build:
	cd ${WRKSRC} && ${CABAL} build

do-install:
	cd ${WRKSRC} && ${CABAL} install

.include <bsd.port.mk>
