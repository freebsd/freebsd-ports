# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tktreectrl
DISTVERSION=	2.0.2
CATEGORIES=	x11-toolkits tk python
MASTER_SITES=	SF/tkintertreectrl/TkinterTreectrl-${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TkinterTreectrl-${DISTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	TkTreectrl Python bindings

LICENSE=	PD

LIB_DEPENDS=	libtreectrl.so.1:x11-toolkits/tktreectrl # no libtreectrl.so is provided by x11-toolkits/tktreectrl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Pmw>=0:x11-toolkits/py-Pmw@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${FLAVOR}

# Restrict python to 2.7 because x11-toolkits/py-Pmw is not ready for python 3 yet
USES=		python:2.7 tk:run zip
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
