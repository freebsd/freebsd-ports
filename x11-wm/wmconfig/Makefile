# New ports collection makefile for:	wmconfig
# Whom:					Tommy Scheunemann <net@arrishq.org>
# Date created:		17 August 2003
#
# $FreeBSD$
#

PORTNAME=	wmconfig
PORTVERSION=	1.1.8
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.arrishq.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Menu generation tool for X window managers

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc --mandir=${LOCALBASE}/man

PORTDOCS=	AUTHORS COPYING NEWS README README.de TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmconfig.1x ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/etc/wmconfig
	${RM} -r ${WRKSRC}/samples/wmconfig/CVS
	for i in `cd ${WRKSRC}/samples/wmconfig; ${ECHO_CMD} *`; do \
		${INSTALL_DATA} ${WRKSRC}/samples/wmconfig/$$i ${PREFIX}/etc/wmconfig; \
	done

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
