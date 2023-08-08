PORTNAME=	pyautogui
DISTVERSION=	0.9.53
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyAutoGUI-${DISTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	lets Python control the mouse and keyboard, and other GUI automation tasks
WWW=		https://github.com/asweigart/pyautogui/

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-xlib>0:x11-toolkits/py-python-xlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymsgbox>0:devel/py-pymsgbox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytweening>0:devel/py-pytweening@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscreeze>0:x11/py-pyscreeze@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mouseinfo>0:x11/py-mouseinfo@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
