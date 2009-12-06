# New ports collection makefile for:	xmonad-contrib
# Date created:		2008-01-23
# Whom:		Matthieu Guegan <matt.guegan@free.fr>
#
# $FreeBSD$
#

PORTNAME=	xmonad-contrib
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	x11-wm haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/xmonad-contrib/${PORTVERSION}/

MAINTAINER=	matt.guegan@free.fr
COMMENT=	Third party tiling algorithms, configurations and scripts to xmonad

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		xmonad:${PORTSDIR}/x11-wm/xmonad
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		xmonad:${PORTSDIR}/x11-wm/xmonad
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_XORG=	x11

GHC_VERSION=		6.10.4
XMONADC_VERSION=	${PORTVERSION}
UTF8STR_VERSION=	0.3.5
HSX11XFT_VERSION=	0.3

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
XMONADC_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		XMONADC_VERSION=${XMONADC_VERSION} \
		XMONADC_LIBDIR_REL=${XMONADC_LIBDIR_REL}

# See (1)
OPTIONS=	XFT "Enable Xft support for fonts" On	\
		UTF8 "Enable UTF-8 support" Off

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--haddock-options=-w --prefix=${PREFIX}

# (1)
.if exists(${LOCALBASE}/lib/X11-xft-${HSX11XFT_VERSION}/register.sh)
WITH_XFT=
.elif exists(${LOCALBASE}/lib/utf8-string-${UTF8STR_VERSION}/register.sh)
WITH_UTF8=
.endif

.if defined(WITH_XFT)
CONFIGURE_ARGS+=	--flags="with_xft"
BUILD_DEPENDS+=		hs-x11-xft-ghc>=0.2:${PORTSDIR}/x11/hs-x11-xft-ghc	\
			hs-utf8-string-ghc>=0.1:${PORTSDIR}/devel/hs-utf8-string-ghc
.elif defined(WITH_UTF8)
CONFIGURE_ARGS+=	--flags="with_utf8"
BUILD_DEPENDS+=		hs-utf8-string-ghc>=0.1:${PORTSDIR}/devel/hs-utf8-string-ghc
.endif

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
		     && ${SETUP_CMD} configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${XMONADC_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.post.mk>
