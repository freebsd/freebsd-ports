# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tktreectrl
PORTVERSION=	2.0.1
CATEGORIES=	x11-toolkits tk python
MASTER_SITES=	SF/tkintertreectrl/TkinterTreectrl-${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TkinterTreectrl-${DISTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	TkTreectrl Python bindings

LIB_DEPENDS=	treectrl:${PORTSDIR}/x11-toolkits/tktreectrl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:${PORTSDIR}/x11-toolkits/py-Pmw

USE_TK_RUN=	yes
USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	TkinterTreectrl
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}

NO_STAGE=	yes
.include <bsd.port.mk>
