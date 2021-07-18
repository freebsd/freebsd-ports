PORTNAME=	xdot
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Interactive viewer for Graphviz dot files

LICENSE=	LGPL3+

RUN_DEPENDS=	dot:graphics/graphviz \
		${PYNUMPY}

USES=		gnome python:3.4+
USE_PYTHON=	autoplist distutils
USE_GNOME=	cairo gtk30 pygobject3

NO_ARCH=	yes

.include <bsd.port.mk>
