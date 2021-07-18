PORTNAME=	find-cursor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Simple XLib program to highlight the cursor position

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Carpetsmoker
USE_XORG=	x11 xdamage xext xfixes xrender

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.markdown screenshot.gif

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
