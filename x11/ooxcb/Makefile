# New ports collection Makefile for:	ooxcb
# Date created:				26 June 2009
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	ooxcb
PORTVERSION=	1.1
CATEGORIES=	x11
MASTER_SITES=	http://samurai-x.org/downloads/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Python binding to the X server using xcb

LIB_DEPENDS=	xcb.2:${PORTSDIR}/x11/libxcb

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PLIST_FILES=	${PYTHON_SITELIBDIR:S/${LOCALBASE}\///}/${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

.include <bsd.port.mk>
