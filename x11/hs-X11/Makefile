# New ports collection makefile for:	hs-x11-ghc
# Date created:				2007-09-03
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	x11
PORTVERSION=	1.2.1
CATEGORIES=	x11 haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${GHC_VERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc
DISTNAME=	ghc-${GHC_VERSION}-src-extralibs

PATCH_SITES=	http://lambda.foldr.org/~vs/FreeBSD/ghc-cabal-${GHC_VERSION}/
PATCHFILES=	patch-cabal-${GHC_VERSION}-Setup.hs

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	X11 bindings for Haskell programs

USE_BZIP2=	yes
USE_XLIB=	yes

# include the version verbatim. This will require a revision bump
# on updates, but the correct quoting of `ghc --numeric-version` in the various
# places is a real nightmare.
GHC_VERSION=	6.6.1
PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} \
		PORTVERSION=${PORTVERSION} \
		PORTNAME=${PORTNAME} \
		SUBDIR=lib/ghc-${GHC_VERSION}/cabal

.include <bsd.port.pre.mk>

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS+=	gmp.7:${PORTSDIR}/math/libgmp4
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc

# 'owned' by lang/ghc:
CABALDIR=	${PREFIX}/lib/ghc-${GHC_VERSION}/cabal
CABALCMD=	${LOCALBASE}/bin/runghc Setup.hs
SUBDIR=		${PORTNAME}${PKGNAMESUFFIX}

WRKSRC=	${WRKDIR}/ghc-${GHC_VERSION}/libraries/X11

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure --ghc --prefix=${PREFIX} --libdir=${CABALDIR} \
	 --libsubdir='' --datasubdir=''

do-build:
	cd ${WRKSRC} && ${CABALCMD} build \
	 && ${CABALCMD} --gen-script register

do-install:
	cd ${WRKSRC} && ${CABALCMD} install \
	 && ${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${CABALDIR}/${PORTNAME}-register.sh

.include <bsd.port.post.mk>
