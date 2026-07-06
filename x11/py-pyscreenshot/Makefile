PORTNAME=	pyscreenshot
DISTVERSION=	2.0
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	PyVirtualDisplay-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python module for taking screenshots
WWW=		https://github.com/ponty/pyscreenshot

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}easyprocess>0:devel/py-easyprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}entrypoint2>0:devel/py-entrypoint2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jeepney>=0.8.0:devel/py-jeepney@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mss>0:deskutils/py-mss@${PY_FLAVOR}

USES=		magick:6,run python

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
