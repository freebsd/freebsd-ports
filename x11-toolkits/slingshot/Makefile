# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	slingshot
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		http://komquats.com/distfiles/ \
		LOCAL/cy

DISTNAME=	SlingShot${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Supplemental Libraries to extend Xview

LIB_DEPENDS=	libxview.so:x11-toolkits/xview

WRKSRC=		${WRKDIR}/sspkg2.1
USE_LDCONFIG=	yes
USES=		gmake tar:Z
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV=	OPENWINHOME=${LOCALBASE}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

IMAKECPPFLAGS+=	-DXVDestDir=${STAGEDIR}${PREFIX}
MAKE_ARGS=	STAGEDIR=${STAGEDIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${STAGEDIR}${DOCSDIR}
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/README ${STAGEDIR}${DOCSDIR}/*.ps
.endif

.include <bsd.port.mk>
