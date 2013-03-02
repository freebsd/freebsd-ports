# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tktreectrl
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk python
MASTER_SITES=	http://klappnase.bubble.org/TkinterTreectrl/ CENKES
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TkinterTreectrl-${DISTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	TkTreectrl Python bindings

LIB_DEPENDS=	treectrl.0:${PORTSDIR}/x11-toolkits/tktreectrl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:${PORTSDIR}/x11-toolkits/py-Pmw

USE_TK_RUN=	yes
USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	TkinterTreectrl
PYDISTUTILS_PKGVERSION=	0.8

.include <bsd.port.mk>
