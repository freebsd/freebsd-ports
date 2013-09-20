# Created by: Chris Rees
# $FreeBSD$

PORTNAME=	skinlf
PORTVERSION=	6.7
DISTVERSIONSUFFIX=	-20060722
CATEGORIES=	x11-toolkits java
MASTER_SITES=	https://skinlf.dev.java.net/files/documents/66/37801/ \
		http://www.bayofrum.net/dist/skinlf/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Allows Java developers to write skinnable applications in Swing

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_ZIP=	yes
USE_JAVA=	yes

JAR_NAME=	${PORTNAME}.jar

NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${JAR_NAME} \
		%%JAVAJARDIR%%/themepack.zip

NO_STAGE=	yes
do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} "${WRKSRC}/lib/${JAR_NAME}" ${JAVAJARDIR}/${JAR_NAME}
	${INSTALL_DATA} "${WRKSRC}/lib/themepack.zip" ${JAVAJARDIR}/themepack.zip

.include <bsd.port.mk>
