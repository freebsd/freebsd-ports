# $FreeBSD$

PORTNAME=	pyvirtualdisplay
PORTVERSION=	0.2.1
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyVirtualDisplay-${PORTVERSION}

MAINTAINER=	daniel@blodan.se
COMMENT=	Python wrapper for Xvfb, Xephyr and Xvnc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	xorg-vfbserver>0:x11-servers/xorg-vfbserver \
		xauth>0:x11/xauth \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paver>0:devel/py-paver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cog>=2.3:devel/py-cog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}easyprocess>0:devel/py-easyprocess@${PY_FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python

.include <bsd.port.mk>
