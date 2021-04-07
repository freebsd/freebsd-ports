PORTNAME=	python-xapp
DISTVERSION=	2.0.2
CATEGORIES=	x11 gnome
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@freebsd.org
COMMENT=	Python Xapp library

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		gnome python:3.5+ shebangfix

USE_GNOME=	pygobject3
USE_PYTHON=	autoplist distutils
SHEBANG_GLOB=	*.py

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_PROJECT=	python3-xapp

NO_ARCH=	yes

.include <bsd.port.mk>
