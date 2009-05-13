# New ports collection makefile for:	xmobar
# Date created:				November 7, 2008
# Whom:					Samy Al Bahra <sbahra@kerneled.org>
#
# $FreeBSD$

PORTNAME=	xmobar
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	x11 haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/xmobar/${PORTVERSION}/ \
		http://carte.kerneled.org/mirror/

MAINTAINER=	sbahra@kerneled.org
COMMENT=	Xmobar is a minimalistic text based status bar

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-x11-ghc>=1.4.1:${PORTSDIR}/x11/hs-x11-ghc
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_XORG=	x11

CABAL=		${LOCALBASE}/bin/runghc Setup.lhs
GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
SUBDIR=		lib/${PORTNAME}-${PORTVERSION}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${PORTVERSION}
PORTEXAMPLES=	*

PLIST_SUB=	GHC_VERSION="${GHC_VERSION}"		\
		PORTVERSION=${PORTVERSION}		\
		SUBDIR=${SUBDIR}

OPTIONS=	XFT "Enable Xft support for fonts" Off	\
		UTF8 "Enable UTF-8 support" Off

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--ghc --prefix=${PREFIX}

.if defined(WITH_XFT)
CONFIGURE_ARGS+=	--flags="with_xft"
BUILD_DEPENDS+=		hs-x11-xft-ghc>=0.2:${PORTSDIR}/x11/hs-x11-xft-ghc
.elif defined(WITH_UTF8)
CONFIGURE_ARGS+=	--flags="with_utf8"
BUILD_DEPENDS+=		hs-utf8-string-ghc>=0.1:${PORTSDIR}/devel/hs-utf8-string-ghc
.endif

.if !defined(NOPORTDOCS)
PLIST_SUB+=	RMLIC="@comment "
.else
PLIST_SUB+=	RMLIC=""
.endif

do-configure:
	cd ${WRKSRC} && ${CABAL} configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${CABAL} build

do-install:
	cd ${WRKSRC} && ${CABAL} install --verbose=3
.if !defined(NOPORTDOCS)
.for d in README
	${INSTALL_MAN} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for f in xmobar.config-sample
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
