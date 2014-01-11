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

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		pkgconfig
USE_XORG=	xpm
USE_GNOME=	gtk20

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/wmcliphistrc ${STAGEDIR}${EXAMPLESDIR}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif #NOPORTDOCS

.include <bsd.port.mk>
