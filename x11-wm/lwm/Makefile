# New ports collection makefile for:	lwm
# Date created:		17 March 1998
# Whom:			J Han <hjh@photino.com>
#
# $FreeBSD$
#

PORTNAME=	lwm
PORTVERSION=	1.2.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.jfc.org.uk/files/lwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight window manager

USE_IMAKE=	yes

MAN1=		lwm.1
PORTDOCS=	AUTHORS BUGS ChangeLog README TODO
PLIST_FILES=	bin/lwm

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
