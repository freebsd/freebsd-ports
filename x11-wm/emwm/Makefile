PORTNAME=	emwm
DISTVERSION=	1.3.1
CATEGORIES=	x11-wm
MASTER_SITES=	https://fastestcode.org/dl/
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	stephan@lichtenauer.co.za
COMMENT=	Enhanced Motif Window Manager
WWW=		https://fastestcode.org/emwm.html

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		groff:build motif tar:xz xorg
USE_XORG=	x11 xext xinerama xrandr xt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/emwm ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1 \
		 ${STAGEDIR}${PREFIX}/share/man/man4 \
		 ${STAGEDIR}${PREFIX}/etc/X11 \
		 ${STAGEDIR}${PREFIX}/etc/X11/app-defaults
	${INSTALL_MAN} ${WRKSRC}/src/emwm.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/src/emwmrc.4 ${STAGEDIR}${PREFIX}/share/man/man4
	${INSTALL_DATA} ${WRKSRC}/src/Emwm.ad ${STAGEDIR}${PREFIX}/etc/X11/app-defaults/Emwm
	${INSTALL_DATA} ${WRKSRC}/src/system.emwmrc ${STAGEDIR}${PREFIX}/etc/X11

.include <bsd.port.mk>
