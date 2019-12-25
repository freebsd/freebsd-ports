# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	marco
PORTVERSION=	1.22.4
CATEGORIES=	x11-wm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window manager for the adult in you

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		zenity>=3.0.0:x11/zenity
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libgtop-2.0.so:devel/libgtop
RUN_DEPENDS=	zenity>=3.0.0:x11/zenity

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig \
		tar:xz xorg
USE_XORG=	ice sm x11 xcomposite xcursor xdamage xext xfixes \
		xinerama xrandr xrender
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.marco.gschema.xml

.include <bsd.port.mk>
