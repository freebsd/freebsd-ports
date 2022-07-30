PORTNAME=	menulibre
PORTVERSION=	2.3.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	x11
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Advanced menu editor

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.38:devel/py-python-distutils-extra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=2.0:sysutils/py-psutil@${PY_FLAVOR}
LIB_DEPENDS=	libgnome-menu-3.so:x11/gnome-menus
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		pkexec:sysutils/polkit \
		${PYTHON_PKGNAMEPREFIX}psutil>=2.0:sysutils/py-psutil@${PY_FLAVOR}

USES=		desktop-file-utils gettext gnome python:3.4+
USE_GNOME=	intltool pygobject3
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	bluesabre

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

.include <bsd.port.post.mk>
