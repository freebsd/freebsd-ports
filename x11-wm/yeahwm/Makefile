PORTNAME=	yeahwm
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://phrat.de/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Minimal X11 window manager with BeOS-like tabbed titles
WWW=		http://phrat.de/

LICENSE=	AEWM
LICENSE_NAME=	AEWM License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		xorg
USE_XORG=	x11 xext xinerama
MAKE_ARGS=	CC="${CC}" XROOT="${LOCALBASE}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/yeahwm share/man/man1/yeahwm.1.gz
PORTDOCS=	README*

OPTIONS_DEFINE=	DOCS MOTIF
MOTIF_DESC=	Use Motif hints to find if window should be borderless

MOTIF_BUILD_DEPENDS=	${LOCALBASE}/include/Xm/MwmUtil.h:x11-toolkits/open-motif

post-extract:
	@${SED} -n '/^Copyright (c)/,$$p' \
		${WRKSRC}/README.evilwm > ${LICENSE_FILE}

post-patch:
	@${REINPLACE_CMD} -e 's, -Wall  -Os,-fcommon,' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/DEF_FONT/s,variable,fixed,' ${WRKSRC}/config.h

post-patch-MOTIF-off:
	@${REINPLACE_CMD} -e '/MWM_HINTS/s,define,undef,' ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yeahwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yeahwm.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
