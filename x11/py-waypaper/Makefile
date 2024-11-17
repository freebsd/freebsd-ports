PORTNAME=	waypaper
DISTVERSION=	2.4
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	GUI wallpaper manager for Wayland and Xorg
WWW=		https://anufrievroman.gitbook.io/waypaper

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.44.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>=3.42:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=8.5.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.4.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=4.2.2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio>=2.36.0:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio-ffmpeg>=0.5.1:graphics/py-imageio-ffmpeg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}screeninfo>=0.8.1:x11/py-screeninfo@${PY_FLAVOR} \
		feh:graphics/feh \
		swaybg:x11/swaybg

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
