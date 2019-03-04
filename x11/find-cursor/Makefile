# $FreeBSD$

PORTNAME=	find-cursor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Simple XLib program to highlight the cursor position

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	Carpetsmoker
USE_XORG=	x11 xdamage xext xfixes xrender

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.markdown screenshot.gif

OPTIONS_DEFINE=	DOCS

post-configure:
	${REINPLACE_CMD} -E 's/(.CC.)/\1 $${LDFLAGS}/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
