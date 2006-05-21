# New ports collection makefile for:	SlingShot
# Date created:		5 March 1997
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	slingshot
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTNAME=	SlingShot${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supplemental Libraries to extend Xview

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/sspkg2.1
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	OPENWINHOME=${X11BASE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/README ${DOCSDIR}/*.ps
.endif

.include <bsd.port.mk>
