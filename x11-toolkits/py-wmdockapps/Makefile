# New ports collection makefile for:	pywmdockapps
# Date created:		2007-05-09
# Whom:			David Thiel <lx@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmdockapps
PORTVERSION=	1.21
PORTREVISION=	1
CATEGORIES=	x11-toolkits python windowmaker
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Tools for making dockapps in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pywmdockapps
USE_XORG=	x11 xpm xau xext xfixes xi

post-patch:
	${REINPLACE_CMD} 's|/usr/X11R6|${LOCALBASE}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
