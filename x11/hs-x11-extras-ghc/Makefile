# New ports collection makefile for:	hs-x11-ghc
# Date created:				2007-09-03
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	x11-extras
PORTVERSION=	0.4
CATEGORIES=	x11 haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/X11-extras/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc
DISTNAME=	X11-extras-${PORTVERSION}

MAINTAINER=	jaj@hcl-club.lu
COMMENT=	X11 bindings for Haskell programs

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

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-x11-ghc>=1.2.1:${PORTSDIR}/x11/hs-x11-ghc
LIB_DEPENDS+=	gmp.7:${PORTSDIR}/math/libgmp4
RUN_DEPENDS+=	${BUILD_DEPENDS}

# 'owned' by lang/ghc:
CABALDIR=	${PREFIX}/lib/ghc-${GHC_VERSION}/cabal
CABALCMD=	${LOCALBASE}/bin/runghc Setup.lhs
SUBDIR=		${PORTNAME}${PKGNAMESUFFIX}

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
