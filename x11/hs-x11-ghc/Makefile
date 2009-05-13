# New ports collection makefile for:	hs-x11-ghc
# Date created:				2007-09-03
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	x11
PORTVERSION=	1.4.5
PORTREVISION=	1
CATEGORIES=	x11 haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/X11/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc
DISTNAME=	X11-${PORTVERSION}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	X11 bindings for Haskell programs

# include the version verbatim. This will require a revision bump
# on updates, but the correct quoting of `ghc --numeric-version` in the various
# places is a real nightmare.
GHC_VERSION=	6.8.3
PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} \
		PORTVERSION=${PORTVERSION} \
		PORTNAME=${PORTNAME} \
		SUBDIR=lib/ghc-${GHC_VERSION}/cabal

OPTIONS=	XINERAMA "Build with Xinerama support" off

.include <bsd.port.pre.mk>

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc

USE_XORG=	x11 xext sm

.if defined(WITH_XINERAMA)
USE_XORG+=	xinerama
.endif

# 'owned' by lang/ghc:
CABALDIR=	${PREFIX}/lib/ghc-${GHC_VERSION}/cabal
CABALCMD=	${LOCALBASE}/bin/runghc Setup.hs
DOCSDIR=	${PREFIX}/share/doc/X11-${PORTVERSION}
PORTDOCS=	LICENSE html
SUBDIR=		${PORTNAME}${PKGNAMESUFFIX}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
PLIST_SUB+=	RMLIC="@comment "
.else
PLIST_SUB+=	RMLIC=""
.endif

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure --ghc --prefix=${PREFIX} --libdir=${CABALDIR} \
	 --libsubdir='' --datasubdir=''

do-build:
	cd ${WRKSRC} && ${CABALCMD} build \
	 && ${CABALCMD} --gen-script register
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${CABALCMD} haddock
.endif

do-install:
	cd ${WRKSRC} && ${CABALCMD} install \
	 && ${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${CABALDIR}/${PORTNAME}-register.sh

.include <bsd.port.post.mk>
