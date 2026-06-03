PORTNAME=	pyscreeze
DISTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	cross-platform screenshot module for python
WWW=		https://github.com/asweigart/pyscreeze

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist distutils

DOS2UNIX_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
