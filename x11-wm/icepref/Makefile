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

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GTK=	yes
NO_BUILD=	yes
MAN1=		icepref.1

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
