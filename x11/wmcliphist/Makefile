# New ports collection makefile for:	wmcliphist
# Date created:				Thu Jul  5 14:43:55 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmcliphist
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://linux.nawebu.cz/wmcliphist/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Clipboard history management dockapp for Window Maker

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gtk12

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/.wmcliphistrc ${EXAMPLESDIR}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif #NOPORTDOCS

post-install:
	@${SED} 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|' ${PKGMESSAGE}

.include <bsd.port.mk>
