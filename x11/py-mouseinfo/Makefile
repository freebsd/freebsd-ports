PORTNAME=	mouseinfo
DISTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MouseInfo-${DISTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	application to display XY position and RGB color information
WWW=		https://github.com/asweigart/mouseinfo

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-xlib>0:x11-toolkits/py-python-xlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>0:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist distutils

DOS2UNIX_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
