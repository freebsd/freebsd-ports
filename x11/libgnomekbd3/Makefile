# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/libgnomekbd3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgnomekbd
PORTVERSION=	3.6.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

BUILD_DEPENDS=	libxklavier>=5.2:${PORTSDIR}/x11/libxklavier
LIB_DEPENDS=	xklavier:${PORTSDIR}/x11/libxklavier

LATEST_LINK=	libgnomekbd3

CONFLICTS=	libgnomekbd-2.[0-9]*

NO_STAGE=	yes
USE_XZ=		yes
USE_GNOME=	gnomeprefix ltverhack intltool gtk30 introspection:build
USE_AUTOTOOLS=	libtool
USE_XORG=	ice
INSTALLS_ICONS=	yes
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.libgnomekbd.desktop.gschema.xml \
		org.gnome.libgnomekbd.gschema.xml \
		org.gnome.libgnomekbd.keyboard.gschema.xml

.include <bsd.port.mk>
