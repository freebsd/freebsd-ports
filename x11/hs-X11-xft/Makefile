# New ports collection makefile for:	hs-x11-xft-ghc
# Date created:		2008-10-21
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	x11-xft
PORTVERSION=	0.3
CATEGORIES=	x11 haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/X11-xft/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc
DISTNAME=	X11-xft-${PORTVERSION}

MAINTAINER=	wahjava@gmail.com
COMMENT=	Bindings to the Xft, Xrender and Freetype for Haskell programs

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-x11-ghc>=1.2.1:${PORTSDIR}/x11/hs-x11-ghc \
		hs-utf8-string-ghc>=0.1:${PORTSDIR}/devel/hs-utf8-string-ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-x11-ghc>=1.2.1:${PORTSDIR}/x11/hs-x11-ghc \
		hs-utf8-string-ghc>=0.1:${PORTSDIR}/devel/hs-utf8-string-ghc

USE_XORG=	xft xrender

CABALCMD=	${LOCALBASE}/bin/runghc Setup.lhs
CABALDIR=	${PREFIX}/lib/ghc-${GHC_VERSION}/cabal
GHC_VERSION=	6.8.3
PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} \
		PORTVERSION=${PORTVERSION} \
		PORTNAME=${PORTNAME} \
		SUBDIR=lib/ghc-${GHC_VERSION}/cabal
DOCSDIR=	${PREFIX}/share/doc/X11-xft-${PORTVERSION}

CONFIGURE_ARGS=	--ghc --prefix=${PREFIX} --libdir=${CABALDIR} --libsubdir='' --datasubdir=''

.ifndef (NOPORTDOCS)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
.endif

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${CABALCMD} build && ${CABALCMD} --gen-script register
.ifndef (NOPORTDOCS)
	cd ${WRKSRC} && ${CABALCMD} haddock
.endif

do-install:
	cd ${WRKSRC} && ${CABALCMD} install \
	  && ${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${CABALDIR}/${PORTNAME}-register.sh

.include <bsd.port.mk>
