# ex:ts=8
# New ports collection makefile for:	xdialog
# Date created:			Jan 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xdialog
PORTVERSION=	2.0.3
CATEGORIES=	x11
MASTER_SITES=	http://xdialog.free.fr/
DISTNAME=	${PORTNAME:S/x/X/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_BZIP2=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=	Xdialog.1

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/doc ; \
	  ${CP} *.html *.png ${DATADIR})
.endif

.include <bsd.port.mk>
