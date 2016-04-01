# Created by: Jacob Frelinger <jacob.frelinger@duke.edu>
# $FreeBSD$

PORTNAME=	traitsgui
PORTVERSION=	3.1.0
PORTREVISION=	7
CATEGORIES=	x11-toolkits python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jacob.frelinger@duke.edu
COMMENT=	Gui toolkit derived from the Enthought python traits library

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traitsbackendwx>=3.1.0:x11-toolkits/py-traitsbackendwx
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	enthought

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples \
		&& ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${EXAMPLESDIR}/\{} \;
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs \
		&& ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${DOCSDIR}/\{} \;

.include <bsd.port.mk>
