# New ports collection makefile for:	xrsi
# Date created:		2007-03-17
# Whom:			Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	xrsi
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A minimalist break enforcer for linux/unix for the prevention of RSI

USE_XORG=	x11
PLIST_FILES=	bin/xrsi
PORTDOCS=	Readme Licence

do-build:
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib -lX11 -o ${WRKSRC}/xrsi ${WRKSRC}/xrsi.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrsi ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme  ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/Licence ${DOCSDIR}/
.endif

.include <bsd.port.mk>
