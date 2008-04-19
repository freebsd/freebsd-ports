# New ports collection makefile for:	xrestop
# Date created:         25 Dec 2003
# Whom:                 Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xrestop
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://projects.o-hand.com/sources/${PORTNAME}/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	X11 server side resource usage statistics monitor

USE_XORG=	x11 xext xrender xt xres xproto
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib \
		XLIBS="-L${LOCALBASE}/lib -lX11"

MAN1=		xrestop.1
PLIST_FILES=	bin/xrestop

.include <bsd.port.mk>
