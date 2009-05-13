# New ports collection makefile for:	xmonad-contrib
# Date created:		2008-01-23
# Whom:		Matthieu Guegan <matt.guegan@free.fr>
#
# $FreeBSD$
#

PORTNAME=	xmonad-contrib
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	x11-wm haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/xmonad-contrib/${PORTVERSION}/

MAINTAINER=	matt.guegan@free.fr
COMMENT=	Third party tiling algorithms, configurations and scripts to xmonad

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-x11-ghc>=1.4.1:${PORTSDIR}/x11/hs-x11-ghc \
		xmonad:${PORTSDIR}/x11-wm/xmonad
RUN_DEPENDS=	xmonad:${PORTSDIR}/x11-wm/xmonad
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_XORG=	x11

CABALCMD=	${LOCALBASE}/bin/runghc Setup.lhs
GHC_VERSION=	6.8.3
SUBDIR=		lib/${PORTNAME}-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	LICENSE html
PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		PORTVERSION=${PORTVERSION} \
		SUBDIR=${SUBDIR}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
.else
PLIST_DIRS+=	%%DOCSDIR%%
PLIST_FILES+=	%%DOCSDIR%%/LICENSE
.endif

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure --ghc --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${CABALCMD} build && ${CABALCMD} register --gen-script
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${CABALCMD} haddock
.endif

do-install:
	cd ${WRKSRC} && ${CABALCMD} install
	${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${PREFIX}/${SUBDIR}/register.sh

.include <bsd.port.mk>
