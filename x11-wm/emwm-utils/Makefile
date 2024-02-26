PORTNAME=	emwm-utils
DISTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	https://fastestcode.org/dl/
DISTNAME=	emwm-utils-src-${DISTVERSION}

MAINTAINER=	stephan@lichtenauer.co.za
COMMENT=	Enhanced Motif Window Manager Utilities
WWW=		https://fastestcode.org/emwm.html

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	emwm:x11-wm/emwm

USES=		groff:build motif tar:xz xorg
USE_XORG=	x11 xext xinerama xrandr xscrnsaver xt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/xmsession ${STAGEDIR}${PREFIX}/bin/xmsession
	${INSTALL_PROGRAM} ${WRKSRC}/src/xmtoolbox ${STAGEDIR}${PREFIX}/bin/xmtoolbox
	${INSTALL_PROGRAM} ${WRKSRC}/src/xmsm ${STAGEDIR}${PREFIX}/bin/xmsm
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/src/xmtoolbox.1 ${STAGEDIR}${PREFIX}/share/man/man1/xmtoolbox.1
	${INSTALL_MAN} ${WRKSRC}/src/xmsm.1 ${STAGEDIR}${PREFIX}/share/man/man1/xmsm.1
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/src/XmSm.ad ${STAGEDIR}${PREFIX}/etc/X11/app-defaults/XmSm
	${INSTALL_DATA} ${WRKSRC}/src/XmToolbox.ad ${STAGEDIR}${PREFIX}/etc/X11/app-defaults/XmToolbox
	${INSTALL_DATA} ${WRKSRC}/src/toolboxrc ${STAGEDIR}${PREFIX}/etc/X11/toolboxrc

.include <bsd.port.mk>
