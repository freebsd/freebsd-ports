# $FreeBSD$

PORTNAME=	xdot
PORTVERSION=	0.6
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-06

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Interactive viewer for Graphviz dot files

LICENSE=	LGPL3+

RUN_DEPENDS=	dot:graphics/graphviz

NO_ARCH=	yes
USES=		gnome python:2.7
USE_PYTHON=	autoplist distutils
USE_GNOME=	pygtk2

CONFLICTS_INSTALL=	py*-xdot

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
