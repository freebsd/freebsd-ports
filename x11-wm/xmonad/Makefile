# New ports collection makefile for:	xmonad
# Date created:		2007-10-25
# Whom:			Matthieu Guegan <matt.guegan@free.fr>
#
# $FreeBSD$
#

PORTNAME=	xmonad
PORTVERSION=	0.4
CATEGORIES=	x11-wm haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/xmonad/${PORTVERSION}/

MAINTAINER=	matt.guegan@free.fr
COMMENT=	Xmonad is a minimalist and tiling window manager for X

USE_XLIB=	yes

CABALCMD=	${LOCALBASE}/bin/runghc Setup.lhs

.include <bsd.port.pre.mk>

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-x11-extras-ghc>=0.4:${PORTSDIR}/x11/hs-x11-extras-ghc
LIB_DEPENDS+=	gmp.7:${PORTSDIR}/math/libgmp4

PLIST_FILES=	bin/xmonad
PORTDOCS=	LICENSE
MAN1=		xmonad.1

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure --ghc --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${CABALCMD} build

do-install:
	@cd ${WRKSRC} && ${CABALCMD} install
	${INSTALL_MAN} ${WRKSRC}/man/xmonad.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}

.include <bsd.port.post.mk>
