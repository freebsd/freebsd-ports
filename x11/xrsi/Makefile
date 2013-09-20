# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	xrsi
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimalist break enforcer for Linux/Unix for the prevention of RSI

USE_XORG=	x11
PLIST_FILES=	bin/xrsi
PORTDOCS=	Readme Licence

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib -lX11 -o ${WRKSRC}/xrsi ${WRKSRC}/xrsi.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrsi ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme  ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/Licence ${DOCSDIR}/
.endif

.include <bsd.port.mk>
