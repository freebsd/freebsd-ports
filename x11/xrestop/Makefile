# New ports collection makefile for:	xrestop
# Date created:         25 Dec 2003
# Whom:                 Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xrestop
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.freedesktop.org/Software/${PORTNAME}/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	X11 server side resource usage statistics monitor

LIB_DEPENDS=	X11.6:${PORTSDIR}/x11/XFree86-4-libraries

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CFLAGS=-I${X11BASE}/include \
		LDFLAGS=-L${X11BASE}/lib

MAN1=	xrestop.1

.include <bsd.port.mk>
