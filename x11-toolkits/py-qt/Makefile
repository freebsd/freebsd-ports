# New ports collection makefile for:	PyQt
# Version required:	0.9
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$

PORTNAME=	py-qt
PORTVERSION=	0.11.1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.river-bank.demon.co.uk/software/
DISTNAME=	PyQt-${PORTVERSION}

MAINTAINER=	adsharma@sharmas.dhs.org

LIB_DEPENDS=	sip.2:${PORTSDIR}/devel/sip

USE_QT=		yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	LDFLAGS=-lgcc
CONFIGURE_ARGS= --with-qt-includes=${X11BASE}/include/X11/qt

.include <bsd.port.mk>
