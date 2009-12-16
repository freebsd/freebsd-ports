# New ports collection makefile for:	libgnomekbd
# Date created:		2006-11-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/libgnomekbd/Makefile,v 1.37 2009/09/22 23:24:04 avl Exp $
#

PORTNAME=	libgnomekbd
PORTVERSION=	2.28.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

LIB_DEPENDS=	xklavier.12:${PORTSDIR}/x11/libxklavier \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack ltverhack gconf2
USE_AUTOTOOLS=	libtool:22
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	desktop_gnome_peripherals_keyboard_xkb.schemas

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|-Werror||g'

.include <bsd.port.mk>
