# New ports collection makefile for:	xdialog
# Date created:				Jan 8, 2001
# Whom:					Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xdialog
PORTVERSION=	1.5.0
CATEGORIES=	x11
MASTER_SITES=	http://xdialog.free.fr/
DISTNAME=	${PORTNAME:S/x/X/}-${PORTVERSION}

MAINTAINER=	ijliao@csie.nctu.edu.tw

USE_BZIP2=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.if defined(NOPORTDOCS)
NODOCS=	"@comment "
.endif

PLIST_SUB=	NOPORTDOCS=${NODOCS}

.if defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	${CP} ${WRKSRC}/html/* ${PREFIX}/share/${PORTNAME}
.endif

.include <bsd.port.mk>
