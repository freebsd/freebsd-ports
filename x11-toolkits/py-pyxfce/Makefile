# New ports collection makefile for:	py-pyxfce
# Date created:		2007-03-12
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyxfce
PORTVERSION=	4.4.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits python xfce
MASTER_SITES=	http://pyxfce.xfce.org/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	XFCE bindings for Python

LIB_DEPENDS=	xfcegui4:${PORTSDIR}/x11-toolkits/libxfce4gui \
		xfce4panel:${PORTSDIR}/x11-wm/xfce4-panel \
		xfce4util:${PORTSDIR}/x11/libxfce4util

CONFIGURE_ARGS=	--libdir=${PREFIX}/libdata
GNU_CONFIGURE=	yes

USE_GNOME=	pygtk2
USE_PYTHON=	yes
BROKEN=		no new version released so far to match xfce 4.6.0

.include <bsd.port.mk>
