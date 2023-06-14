PORTNAME=	pynput
DISTVERSION=	1.7.6
CATEGORIES=	x11
MASTER_SITES=	PYPI # no tests on PYPI, but GitHub tarball doesn't bui;d
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Send virtual input commands
WWW=		https://github.com/moses-palmer/pynput

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.3.1:textproc/py-sphinx@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xlib>0:x11-toolkits/py-python-xlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
