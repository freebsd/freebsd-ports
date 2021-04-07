PORTNAME=	pyscreenshot
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	PyVirtualDisplay-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Python module for taking screenshots

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}easyprocess>0:devel/py-easyprocess@${PY_FLAVOR} \
		${PY_PILLOW} \
		import:graphics/ImageMagick6

USES=		python:3.6+

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
