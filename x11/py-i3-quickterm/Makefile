PORTNAME=	i3-quickterm
DISTVERSION=	1.1
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Drop-down "quake style" terminal for i3 and sway

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}i3ipc>2.0:x11/py-i3ipc@${PY_FLAVOR}
USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
