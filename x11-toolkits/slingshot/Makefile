# New ports collection makefile for:	SlingShot
# Date created:		5 March 1997
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	slingshot
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTNAME=	SlingShot${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supplemental Libraries to extend Xview

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/sspkg2.1
USE_LDCONFIG=	yes
USE_GMAKE=	yes
MAKE_ENV=	OPENWINHOME=${LOCALBASE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/README ${DOCSDIR}/*.ps
.endif

.include <bsd.port.mk>
