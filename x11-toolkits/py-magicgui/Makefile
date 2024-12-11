PORTNAME=	magicgui
DISTVERSION=	0.9.1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Build GUIs from python types
WWW=		https://pyapp-kit.github.io/magicgui/ \
		https://github.com/pyapp-kit/magicgui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docstring-parser>=0.7:textproc/py-docstring-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psygnal>=0.6.1:devel/py-psygnal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=1.7.0:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}superqt>=0.6.1:x11-toolkits/py-superqt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
