# New ports collection makefile for:	icepref
# Date created:		06 June 2000
# Whom:				Michael Urban <murban@tznet.com>
#
# $FreeBSD$
#

PORTNAME=	icepref
PORTVERSION=	1.1
PORTREVISION=	1
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
