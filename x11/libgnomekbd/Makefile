# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/libgnomekbd/Makefile 19593 2014-04-28 11:41:58Z gusi $

PORTNAME=	libgnomekbd
PORTVERSION=	3.6.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

BUILD_DEPENDS=	libxklavier>=5.2:${PORTSDIR}/x11/libxklavier
LIB_DEPENDS=	libxklavier.so:${PORTSDIR}/x11/libxklavier

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intltool introspection:build \
		libxml2
GNU_CONFIGURE=	yes
USE_XORG=	ice
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.libgnomekbd.desktop.gschema.xml \
		org.gnome.libgnomekbd.gschema.xml \
		org.gnome.libgnomekbd.keyboard.gschema.xml

.include <bsd.port.mk>
