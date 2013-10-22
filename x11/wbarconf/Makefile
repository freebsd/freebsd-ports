# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	wbarconf
PORTVERSION=	0.7.2.2
CATEGORIES=	x11
MASTER_SITES=	http://koti.kapsi.fi/ighea/wbarconf/
DISTNAME=	wbarconf-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	Configuration GUI for wbar

RUN_DEPENDS=	wbar:${PORTSDIR}/x11/wbar

USE_GNOME=	pygobject pygtk2 gtk20
USE_PYTHON=	2.5+
USES=		gettext
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	README COPYING

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/wbarbacks
	(cd ${WRKSRC}/wbarbacks/ && ${COPYTREE_SHARE} \* ${DATADIR}/wbarbacks/)
	${INSTALL_DATA} ${WRKSRC}/messages.pot ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/wbarconf.png ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/wbarconf.desktop ${PREFIX}/share/applications
	(cd ${WRKSRC}/locale/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/locale/)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
