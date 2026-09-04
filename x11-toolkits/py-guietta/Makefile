PORTNAME=	guietta
DISTVERSION=	1.6.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Simple GUI for Python
WWW=		https://github.com/alfiopuglisi/guietta

LICENSE=	MIT

DEPRECATED=    Abandoned, depends on deprecated PySide2
EXPIRATION_DATE=       2026-09-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyside2>=0:devel/pyside2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
