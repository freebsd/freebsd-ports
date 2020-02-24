# $FreeBSD$

PORTNAME=	pyvirtualdisplay
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyVirtualDisplay-${PORTVERSION}

MAINTAINER=	daniel@blodan.se
COMMENT=	Python wrapper for Xvfb, Xephyr and Xvnc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cog>=2.3:devel/py-cog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}easyprocess>0:devel/py-easyprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paver>0:devel/py-paver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscreenshot>0:x11/py-pyscreenshot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
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

XVFB_RUN_DEPENDS=	xorg-vfbserver>0:x11-servers/xorg-vfbserver
XEPHYR_RUN_DEPENDS=	xephyr>=0:x11-servers/xephyr
XVNC_RUN_DEPENDS=	tightvnc>=0:net/tightvnc

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pillow6>0:graphics/py-pillow6@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
