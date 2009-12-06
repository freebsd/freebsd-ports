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

GHC_VERSION=		6.10.4
HSX11XFT_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
HSX11XFT_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HSX11XFT_VERSION=${HSX11XFT_VERSION} \
		HSX11XFT_LIBDIR_REL=${HSX11XFT_LIBDIR_REL}

.if defined(NOPORTDOCS)
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

.if !defined(NOPORTDOCS)

PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if !empty(PORT_HADDOCK:M?0)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
.endif
BUILD_DEPENDS+=	HsColour:${PORTSDIR}/print/hs-hscolour

HSCOLOUR_VERSION=	1.15
HSCOLOUR_DATADIR=	${PREFIX}/share/hscolour-${HSCOLOUR_VERSION}

PORTDOCS=	*
.endif

.SILENT:

do-configure:
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.lhs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${HSX11XFT_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
