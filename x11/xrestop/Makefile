# New ports collection makefile for:	xrestop
# Date created:         25 Dec 2003
# Whom:                 Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xrestop
PORTVERSION=	0.3
CATEGORIES=	x11
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	X11 server side resource usage statistics monitor

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CFLAGS=-I${X11BASE}/include \
		LDFLAGS=-L${X11BASE}/lib

MAN1=		xrestop.1
PLIST_FILES=	bin/xrestop

.include <bsd.port.mk>
