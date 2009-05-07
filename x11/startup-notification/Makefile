# New ports collection makefile for:	startup-notification
# Date created:				14 November 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11/startup-notification/Makefile,v 1.8 2006/09/10 00:51:15 mezz Exp $

PORTNAME=	startup-notification
PORTVERSION=	0.10
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.freedesktop.org/software/startup-notification/releases/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library that supports startup notification spec from freedesktop.org

LIB_DEPENDS=	xcb-aux.0:${PORTSDIR}/x11/xcb-util

USE_XORG=	x11
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
