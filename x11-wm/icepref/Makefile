# New ports collection makefile for:	icepref
# Date created:		06 June 2000
# Whom:				Michael Urban <murban@tznet.com>
#
# $FreeBSD$
#

PORTNAME=	icepref
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_NETBSD}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small graphical configuration utility for the Ice Window Manager

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GNOME=	gtk12
NO_BUILD=	yes
MAN1=		icepref.1

PORTDOCS=	README FAQ LICENSE
PLIST_FILES=	bin/icepref

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/icepref ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icepref.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for DOC in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
