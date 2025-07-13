PORTNAME=	python-xapp
DISTVERSION=	2.4.2
CATEGORIES=	x11 gnome
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@freebsd.org
COMMENT=	Python Xapp library
WWW=		https://github.com/linuxmint/python3-xapp

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		gnome meson python shebangfix

USE_GNOME=	pygobject3
USE_PYTHON=	flavors
SHEBANG_GLOB=	*.py
BINARY_ALIAS=	python3=${PYTHON_CMD}

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_PROJECT=	python3-xapp

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} 's|/usr/bin|${PREFIX}/bin|g' ${WRKSRC}/xapp/os.py

.include <bsd.port.mk>
