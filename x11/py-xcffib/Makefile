PORTNAME=	xcffib
PORTVERSION=	1.11.2
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Replacement for xpyb and XCB Python bindings
WWW=		https://github.com/tych0/xcffib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libxcb.so:x11/libxcb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:devel/py-cffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
