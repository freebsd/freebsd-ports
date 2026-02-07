PORTNAME=	xdot
DISTVERSION=	1.6
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Interactive viewer for Graphviz dot files
WWW=		https://pypi.org/project/xdot/ \
		https://github.com/jrfonseca/xdot.py/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	dot:graphics/graphviz \
		${PYNUMPY}

USES=		gnome python
USE_GNOME=	cairo gtk30 pygobject3
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
