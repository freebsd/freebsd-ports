# ex:ts=8
# New ports collection makefile for:	xdialog
# Date created:			Jan 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xdialog
PORTVERSION=	1.5.3
CATEGORIES=	x11
MASTER_SITES=	http://xdialog.free.fr/
DISTNAME=	${PORTNAME:S/x/X/}-${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org

USE_BZIP2=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=	Xdialog.1

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	@(cd ${WRKSRC}/doc ; \
	  ${CP} *.html *.png ${PREFIX}/share/${PORTNAME})
.endif

.include <bsd.port.mk>
