# $FreeBSD$

PORTNAME=	qwt
PORTVERSION=	5.2.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
PKGNAMESUFFIX=	5

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt Widgets for Technical Applications

USES=		gmake qmake
USE_QT4=	gui svg moc_build
USE_BZIP2=	yes
USE_LDCONFIG=	yes
PORTSCOUT=	limit:^5\.

PORTDOCS=	*
PLIST_SUB=	SHLIB_VER=${PORTVERSION} \
		SHLIB_SHVER=${PORTVERSION:R}

STRIP_FILES=	lib/libqwt.so.${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/Qwt* ${STAGEDIR}${PREFIX}/man/man3
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
