# New ports collection makefile for:	wbarconf
# Date created:		21 may 2009
# Whom:			Olivier Cochard-Labbe <olivier@cochard.me>
#
# $FreeBSD$
#

PORTNAME=	wbarconf
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.ihku.biz/wbarconf/
DISTNAME=	wbarconf-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	Configuration GUI for wbar

RUN_DEPENDS=	wbar:${PORTSDIR}/x11/wbar

USE_GNOME=	pygtk2
USE_PYTHON=	2.4+
USE_GETTEXT=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	README COPYING

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/wbarbacks
	(cd ${WRKSRC}/wbarbacks/ && ${COPYTREE_SHARE} \* ${DATADIR}/wbarbacks/)
	${INSTALL_DATA} ${WRKSRC}/messages.pot ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/wbarconf.png ${PREFIX}/share/pixmaps
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/wbarconf.desktop ${PREFIX}/share/applications
	(cd ${WRKSRC}/locale/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/locale/)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
