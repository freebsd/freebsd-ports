# $FreeBSD$

PORTNAME=	qwt
PORTVERSION=	5.2.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
PKGNAMESUFFIX=	5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt Widgets for Technical Applications

USES=		gmake qmake tar:bzip2
USE_QT4=	gui svg moc_build
USE_LDCONFIG=	yes
PORTSCOUT=	limit:^5\.

PORTDOCS=	*
PLIST_SUB=	SHLIB_VER=${PORTVERSION} \
		SHLIB_SHVER=${PORTVERSION:R}

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/Qwt* ${STAGEDIR}${PREFIX}/man/man3

post-install-DOCS-on:
	(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
