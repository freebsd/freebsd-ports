PORTNAME=	xdot
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	x11 python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive viewer for Graphviz dot files
WWW=		https://pypi.org/project/xdot/

LICENSE=	LGPL3+

RUN_DEPENDS=	dot:graphics/graphviz \
		${PYNUMPY}

USES=		gnome python
USE_PYTHON=	autoplist distutils
USE_GNOME=	cairo gtk30 pygobject3

NO_ARCH=	yes

.include <bsd.port.mk>
