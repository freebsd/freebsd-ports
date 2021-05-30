PORTNAME=	i3-quickterm
DISTVERSION=	1.0
CATEGORIES=	x11 python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Drop-down "quake style" terminal for i3 and sway

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}i3ipc>2.0:x11/py-i3ipc@${PY_FLAVOR} \

USES=		cpe python:3.4+
USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes

.include <bsd.port.mk>
