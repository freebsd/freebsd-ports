# New ports collection makefile for:	py-libsexy
# Date created:		09 December 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sexy
PORTVERSION=	0.1.9
PORTREVISION=	3
DISTVERSIONPREFIX=	python-
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://releases.chipx86.com/libsexy/sexy-python/ CENKES
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libsexy bindings for Python

LIB_DEPENDS=	sexy.2:${PORTSDIR}/x11-toolkits/libsexy

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	pygtk2 pkgconfig
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
