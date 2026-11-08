PORTNAME=	superqt
DISTVERSION=	0.9.0
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Missing widgets and components for PyQt/PySide
WWW=		https://pyapp-kit.github.io/superqt/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=2.4.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=2.4.0:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cmap>=0.6.2:misc/py-cmap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0.24.4:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyconify>=0.2.1:devel/py-pyconify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>=6.7.0:devel/pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-qt>=4.5.0:devel/py-pytest-qt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# test_qiconify needs network access
TEST_ARGS=	--disable-plugin-autoload -p pytestqt.plugin \
		--deselect=tests/test_iconify.py::test_qiconify
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} QT_API=pyside6 QT_QPA_PLATFORM=offscreen

# tests as of 0.9.0: 424 passed, 50 skipped, 1 deselected, 1 xfailed in 6.00s

.include <bsd.port.mk>
