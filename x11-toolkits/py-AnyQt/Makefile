PORTNAME=	AnyQt
DISTVERSION=	0.2.2
CATEGORIES=	x11-toolkits devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyQt4/PyQt5 compatibility layer
WWW=		https://github.com/ales-erjavec/anyqt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt6-pyqt>0:devel/py-qt6-pyqt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_BUILD=	yes
NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} QT_API=pyqt6 QT_QPA_PLATFORM=offscreen
TEST_ARGS=	--disable-plugin-autoload

# tests as of 0.2.2: 13 passed, 1 skipped in 1.27s

.include <bsd.port.mk>
