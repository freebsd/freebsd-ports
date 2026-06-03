PORTNAME=	xmonad
DISTVERSION=	0.18.1
CATEGORIES=	x11-wm haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tiling window manager
WWW=		https://xmonad.org/ \
		https://github.com/xmonad/xmonad/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ghc:lang/ghc

USES=		cabal xorg
USE_XORG=	x11 xext xinerama xrandr xscrnsaver

PIE_UNSAFE=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xmonad.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/man/xmonad.hs ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/example_buildscript ${STAGEDIR}${EXAMPLESDIR}/build
	${INSTALL_DATA} ${FILESDIR}/example_config.cabal ${STAGEDIR}${EXAMPLESDIR}/xmonad-config.cabal

.include <bsd.port.mk>
