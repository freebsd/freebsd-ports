# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	slingshot
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		http://komquats.com/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     cy

DISTNAME=	SlingShot${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Supplemental Libraries to extend Xview

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/sspkg2.1
USE_LDCONFIG=	yes
USES=		gmake
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV=	OPENWINHOME=${LOCALBASE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/README ${DOCSDIR}/*.ps
.endif

.include <bsd.port.mk>
