# Created by: David Thiel <lx@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmdockapps
PORTVERSION=	1.21
PORTREVISION=	3
CATEGORIES=	x11-toolkits python windowmaker
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Tools for making dockapps in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

USE_XORG=	x11 xpm xau xext xfixes xi

post-patch:
	${REINPLACE_CMD} 's|/usr/X11R6|${LOCALBASE}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
