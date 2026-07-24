PORTNAME=	pyscreenshot
DISTVERSION=	3.1
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	PyVirtualDisplay-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python module for taking screenshots
WWW=		https://github.com/ponty/pyscreenshot

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=		Deprecated in favor of py-pillow
EXPIRATION_DATE=	2026-10-31

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}easyprocess>0:devel/py-easyprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}entrypoint2>0:devel/py-entrypoint2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jeepney>0:devel/py-jeepney@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mss>0:deskutils/py-mss@${PY_FLAVOR}

USES=		magick:6,run python

NO_ARCH=	yes
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
