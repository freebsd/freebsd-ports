# New ports collection makefile for:	wmconfig
# Whom:					Tommy Scheunemann <net@arrishq.org>
# Date created:		17 August 2003
#
# $FreeBSD$
#

PORTNAME=	wmconfig
PORTVERSION=	1.3.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.arrishq.net/downloads/

MAINTAINER=	net@arrishq.net
COMMENT=	Menu generation tool for X window managers

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN1=		wmconfig.1x

PORTDOCS=	AUTHORS ChangeLog COPYING README TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
