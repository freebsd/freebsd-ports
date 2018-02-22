# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tktreectrl
DISTVERSION=	2.0.2
CATEGORIES=	x11-toolkits tk python
MASTER_SITES=	SF/tkintertreectrl/TkinterTreectrl-${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TkinterTreectrl-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TkTreectrl Python bindings

LICENSE=	PD

LIB_DEPENDS=	libtreectrl.so.1:x11-toolkits/tktreectrl # no libtreectrl.so is provided by x11-toolkits/tktreectrl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${FLAVOR} \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:x11-toolkits/py-Pmw@${FLAVOR}

USES=		python:2.7 tk:run zip # 2.7 is only because x11-toolkits/py-Pmw has USES=python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PYDISTUTILS_PKGNAME=	TkinterTreectrl
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}

.include <bsd.port.mk>
