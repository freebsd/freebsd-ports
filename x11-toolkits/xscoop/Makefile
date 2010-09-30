# New ports collection makefile for:	xscoop
# Date created:				Sa 04 Nov 2005 00:00:00 MET DST
# Whom:					Ron Scheckelhoff <rscheckelhoff@fourcalorieservers.com
#
# $FreeBSD$
#

PORTNAME=	xscoop
PORTVERSION=	1.0.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.fourcalorieservers.com/ports/x11-toolkits/xscoop/ \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X library detective

BROKEN=		does not fetch

MAN7=		xscoop.7
PLIST_FILES=	bin/xscoop
PORTDOCS=	xscoop.pdf
NO_BUILD=	yes

# distfile contains i386 binary
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xscoop6 ${PREFIX}/bin/xscoop
	${INSTALL_MAN} ${WRKSRC}/xscoop.7 ${MAN7PREFIX}/man/man7/xscoop.7
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/xscoop.pdf ${DOCSDIR}/xscoop.pdf

.include <bsd.port.post.mk>
