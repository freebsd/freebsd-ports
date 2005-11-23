# New ports collection makefile for:	xscoop
# Date created:				Sa 04 Nov 2005 00:00:00 MET DST
# Whom:					Ron Scheckelhoff <rscheckelhoff@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xscoop
PORTVERSION=	1.0.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.datazygte.com/ports/x11-toolkits/xscoop/

MAINTAINER=	rscheckelhoff@yahoo.com
COMMENT=	An X library detective

MAN7=		xscoop.7
PLIST_FILES=	bin/xscoop
PORTDOCS=	xscoop.pdf
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xscoop ${PREFIX}/bin/xscoop
	${INSTALL_MAN} ${WRKSRC}/xscoop.7 ${MAN7PREFIX}/man/man7/xscoop.7
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/xscoop.pdf ${DOCSDIR}/xscoop.pdf

.include <bsd.port.mk>
