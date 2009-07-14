# New ports collection makefile for:	tkintertreectrl
# Date created:		09 December 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tktreectrl
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk python
MASTER_SITES=	http://klappnase.bubble.org/TkinterTreectrl/ CENKES
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TkinterTreectrl-${DISTVERSION}

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	TkTreectrl Python bindings

LIB_DEPENDS=	treectrl.0:${PORTSDIR}/x11-toolkits/tktreectrl
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:${PORTSDIR}/x11-toolkits/py-Pmw

USE_TK_RUN=	yes
USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	TkinterTreectrl
PYDISTUTILS_PKGVERSION=	0.4

.include <bsd.port.mk>
