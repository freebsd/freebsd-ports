# New ports collection makefile for:	icepref
# Date created:		06 June 2000
# Whom:				Michael Urban <murban@tznet.com>
#
# $FreeBSD$
#

PORTNAME=	icepref
PORTVERSION=	1.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://209.132.18.205/downloads/portfiles/

MAINTAINER=	murban@tznet.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	${LOCALBASE}/lib/python1.5/site-packages/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
NO_BUILD=	yes
MAN1=		icepref.1
FETCH_BEFORE_ARGS=	-b
.if defined(NOPORTDOCS)
PLIST_SUB+=	PORTDOCS="@comment "
.else
PLIST_SUB+=	PORTDOCS=""
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/icepref ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icepref.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/icepref
.for DOC in README FAQ LICENSE
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/icepref
.endfor
.endif

.include <bsd.port.mk>
