# Created by: Jacob Frelinger <jacob.frelinger@duke.edu>
# $FreeBSD$

PORTNAME=	traitsbackendwx
PORTVERSION=	3.2.0
PORTREVISION=	8
CATEGORIES=	x11-toolkits python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TraitsBackendWX-${PORTVERSION}

MAINTAINER=	jacob.frelinger@duke.edu
COMMENT=	Wx backend for TraitsGUI

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>=3.2.0:${PORTSDIR}/devel/py-traits
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_WX=		3.0+
WX_COMPS=	python

.include <bsd.port.mk>

