# Created by: Matthieu Guegan <matt.guegan@free.fr>
# $FreeBSD$

PORTNAME=	xmonad
PORTVERSION=	0.15
PORTREVISION=	4
CATEGORIES=	x11-wm haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tiling window manager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ghc:lang/ghc

USES=		cabal xorg

USE_XORG=	x11 xext xinerama xrandr xscrnsaver

USE_CABAL=	X11-1.9.1 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		dlist-0.8.0.8 \
		extensible-exceptions-0.1.1.4 \
		hsc2hs-0.68.6 \
		old-locale-1.0.0.7_2 \
		setlocale-1.0.0.9_1 \
		utf8-string-1.0.1.1_3

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xmonad.1 ${STAGEDIR}${MANPREFIX}/man/man1/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PATCHDIR}/example_buildscript ${STAGEDIR}${EXAMPLESDIR}/build
	${INSTALL_DATA} ${PATCHDIR}/example_config.cabal ${STAGEDIR}${EXAMPLESDIR}/xmonad-config.cabal
	${INSTALL_DATA} ${WRKSRC}/man/xmonad.hs ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
