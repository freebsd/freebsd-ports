# New ports collection makefile for:	xscoop
# Date created:				Sa 04 Nov 2005 00:00:00 MET DST
# Whom:					Ron Scheckelhoff <rscheckelhoff@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xscoop
PORTVERSION=	1.0.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://people.tecnik93.com/~itetcu/FreeBSD/others_ports/${PORTNAME}/sources/

MAINTAINER=	rscheckelhoff@yahoo.com
COMMENT=	An X library detective

MAN7=		xscoop.7
PLIST_FILES=	bin/xscoop
PORTDOCS=	xscoop.pdf
NO_BUILD=	yes

# distfile contains i386 binary
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION}>=600000
EXEFILE=	xscoop6
.else
EXEFILE=	xscoop5
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${EXEFILE} ${PREFIX}/bin/xscoop
	${INSTALL_MAN} ${WRKSRC}/xscoop.7 ${MAN7PREFIX}/man/man7/xscoop.7
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/xscoop.pdf ${DOCSDIR}/xscoop.pdf

.include <bsd.port.post.mk>
