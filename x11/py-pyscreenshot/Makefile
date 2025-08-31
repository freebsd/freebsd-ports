PORTNAME=	pyscreenshot
PORTVERSION=	0.5.1
PORTREVISION=	6
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
		${PY_PILLOW}

USES=		magick:6,run python

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
