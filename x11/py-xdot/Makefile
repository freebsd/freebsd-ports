# $FreeBSD$

PORTNAME=	xdot
PORTVERSION=	0.9
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Interactive viewer for Graphviz dot files

LICENSE=	LGPL3+

RUN_DEPENDS=	dot:graphics/graphviz

NO_ARCH=	yes
USES=		python:3.4+
USE_PYTHON=	autoplist distutils
USE_GNOME=	cairo gtk30 pygobject3

CONFLICTS_INSTALL=	py*-xdot-06

.include <bsd.port.mk>
