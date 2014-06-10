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

LIB_DEPENDS=	libxview.so:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/sspkg2.1
USE_LDCONFIG=	yes
USES=		gmake
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV=	OPENWINHOME=${LOCALBASE}

.include <bsd.port.pre.mk>

IMAKECPPFLAGS+=	-DXVDestDir=${STAGEDIR}${PREFIX}
MAKE_ARGS=	STAGEDIR=${STAGEDIR}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${STAGEDIR}${DOCSDIR}
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/README ${STAGEDIR}${DOCSDIR}/*.ps
.endif

.include <bsd.port.post.mk>
