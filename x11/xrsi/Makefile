# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	xrsi
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimalist break enforcer for Linux/Unix for the prevention of RSI

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/Licence

USES=		xorg
USE_XORG=	x11
PLIST_FILES=	bin/xrsi
PORTDOCS=	Readme

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib -lX11 -o ${WRKSRC}/xrsi ${WRKSRC}/xrsi.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrsi ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
