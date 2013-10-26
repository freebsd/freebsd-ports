# Created by: Jacob Frelinger <jacob.frelinger@duke.edu>
# $FreeBSD$

PORTNAME=	traitsbackendwx
PORTVERSION=	3.2.0
PORTREVISION=	4
CATEGORIES=	x11-toolkits python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TraitsBackendWX-${PORTVERSION}

MAINTAINER=	jacob.frelinger@duke.edu
COMMENT=	Wx backend for TraitsGUI

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>=3.2.0:${PORTSDIR}/devel/py-traits
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TraitsBackendWX
PYEASYINSTALL_UNINSTALLARGS=	-q -m -N -S ${PYTHON_SITELIBDIR} ${PYDISTUTILS_PKGNAME}==${PYDISTUTILS_PKGVERSION}
USE_WX=		2.8
WX_COMPS=	python

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
