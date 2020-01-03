# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sexy
PORTVERSION=	0.1.9
PORTREVISION=	8
DISTVERSIONPREFIX=	python-
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://releases.chipx86.com/libsexy/sexy-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libsexy bindings for Python

LICENSE=	LGPL21

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-02-04

LIB_DEPENDS=	libsexy.so:x11-toolkits/libsexy

USES=		gnome libtool pkgconfig python:2.7
USE_GNOME=	pygtk2
USE_PYTHON=	flavors
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
