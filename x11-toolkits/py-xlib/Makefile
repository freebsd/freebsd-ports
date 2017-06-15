# Created by: Mike Meyer <mwm@mired.org>
# $FreeBSD$

PORTNAME=	xlib
PORTVERSION=	0.18
CATEGORIES=	x11-toolkits python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fax@nohik.ee
COMMENT=	X11 library for Python

LICENSE=	GPLv2+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.7:devel/py-setuptools_scm \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six

USE_GITHUB=	yes
GH_ACCOUNT=	python-xlib
GH_PROJECT=	python-xlib

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
