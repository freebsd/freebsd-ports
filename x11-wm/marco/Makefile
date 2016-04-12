# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	marco
PORTVERSION=	1.12.1
CATEGORIES=	x11-wm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window manager for the adult in you

BUILD_DEPENDS=	itstool:textproc/itstool \
		zenity>=3.0.0:x11/zenity
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libcanberra-gtk.so:audio/libcanberra \
		libgtop-2.0.so:devel/libgtop
RUN_DEPENDS=	zenity>=3.0.0:x11/zenity

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_XORG=	x11 xcomposite xcursor xdamage xrandr
USE_GNOME=	gdkpixbuf2 glib20 gtk20 intlhack pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.marco.gschema.xml

.include <bsd.port.mk>
