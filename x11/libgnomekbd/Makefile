# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/libgnomekbd/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgnomekbd
PORTVERSION=	2.32.0
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

LIB_DEPENDS=	libxklavier.so:${PORTSDIR}/x11/libxklavier

CONFLICTS=	libgnomekbd-3.[0-9]*

USE_BZIP2=	yes
USE_GNOME=	gnomeprefix ltverhack gconf2
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	desktop_gnome_peripherals_keyboard_xkb.schemas

.include <bsd.port.mk>
