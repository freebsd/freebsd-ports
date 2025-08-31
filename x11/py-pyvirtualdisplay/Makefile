PORTNAME=	pyvirtualdisplay
PORTVERSION=	0.2.4
PORTREVISION=	4
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyVirtualDisplay-${PORTVERSION}

MAINTAINER=	daniel@blodan.se
COMMENT=	Python wrapper for Xvfb, Xephyr and Xvnc
WWW=		https://github.com/ponty/pyvirtualdisplay

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cogapp>=2.3:devel/py-cogapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}easyprocess>0:devel/py-easyprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paver>0:devel/py-paver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscreenshot>0:x11/py-pyscreenshot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PY_PILLOW} \
		xauth>0:x11/xauth

USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	XEPHYR XVFB XVNC
OPTIONS_DEFAULT=	XVFB
BACKEND_DESC=		Virtual Backend To Install
XVFB_DESC=		Install Xvfb backend
XEPHYR_DESC=		Install Xephyr backend
XVNC_DESC=		Install Xvnc backend

XVFB_RUN_DEPENDS=	Xvfb:x11-servers/xorg-server@xvfb
XEPHYR_RUN_DEPENDS=	Xephyr:x11-servers/xorg-server@xephyr
XVNC_RUN_DEPENDS=	tightvnc>=0:net/tightvnc

NO_ARCH=	yes

.include <bsd.port.mk>
