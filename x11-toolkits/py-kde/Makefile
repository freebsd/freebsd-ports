# New ports collection makefile for:	PyKDE
# Version required:	0.9
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$
#

PORTNAME=	py-kde
PORTVERSION=	0.12
CATEGORIES=	x11-toolkits kde python
MASTER_SITES=	http://www.river-bank.demon.co.uk/software/
DISTNAME=	PyKDE-${PORTVERSION}

MAINTAINER=	adsharma@sharmas.dhs.org

BUILD_DEPENDS=	${LOCALBASE}/lib/python1.5/qt.py:${PORTSDIR}/x11-toolkits/py-qt

USE_LIBTOOL=	yes
USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS= --with-qt-includes=${X11BASE}/include/X11/qt

.include <bsd.port.mk>
