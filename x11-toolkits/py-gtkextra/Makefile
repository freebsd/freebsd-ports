# ex:ts=8
# Ports collection makefile for:	py-gtkextra
# Date created:			May 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkextra
PORTVERSION=	0.22
PORTREVISION=	5
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GtkExtra Python Language Bindings

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk
LIB_DEPENDS=	gtkextra.17:${PORTSDIR}/x11-toolkits/gtkextra
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python-gtkextra

.include <bsd.port.mk>
