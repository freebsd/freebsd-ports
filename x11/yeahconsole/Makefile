# Created by: Satoshi Asami <asami@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yeahconsole
PORTVERSION=	0.3.4
CATEGORIES=	x11
MASTER_SITES=	http://phrat.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal wrapper for creating drop-down consoles

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		xorg
USE_XORG=	x11
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/yeahconsole
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
