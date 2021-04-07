PORTNAME=	skinlf
PORTVERSION=	6.7
DISTVERSIONSUFFIX=	-20060722
CATEGORIES=	x11-toolkits java
MASTER_SITES=	https://skinlf.dev.java.net/files/documents/66/37801/ \
		http://www.bayofrum.net/dist/skinlf/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Allows Java developers to write skinnable applications in Swing

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		zip
USE_JAVA=	yes

JAR_NAME=	${PORTNAME}.jar

NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${JAR_NAME} \
		%%JAVAJARDIR%%/themepack.zip

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/${JAR_NAME} \
		${STAGEDIR}${JAVAJARDIR}/${JAR_NAME}
	${INSTALL_DATA} ${WRKSRC}/lib/themepack.zip \
		${STAGEDIR}${JAVAJARDIR}/themepack.zip

.include <bsd.port.mk>
