# Created by: Mike Meyer <mwm@mired.org>
# $FreeBSD$

PORTNAME=	xlib
PORTVERSION=	0.21
CATEGORIES=	x11-toolkits python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fax@nohik.ee
COMMENT=	X11 library for Python

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.7:devel/py-setuptools_scm@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	python-xlib
GH_PROJECT=	python-xlib

USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
