# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	wmcliphist
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://linux.nawebu.cz/wmcliphist/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Clipboard history management dockapp for Window Maker

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		pkgconfig
USE_XORG=	xpm
USE_GNOME=	gtk20

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/wmcliphistrc ${EXAMPLESDIR}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif #NOPORTDOCS

post-install:
	@${SED} 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|' ${PKGMESSAGE}

.include <bsd.port.mk>
