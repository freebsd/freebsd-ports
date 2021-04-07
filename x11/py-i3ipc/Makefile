PORTNAME=	i3ipc
PORTVERSION=	2.2.1
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Improved Python library to control i3wm and sway

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlib>0:x11-toolkits/py-xlib@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.4+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
