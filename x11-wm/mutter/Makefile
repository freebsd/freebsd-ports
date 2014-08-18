# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11-wm/mutter/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	mutter
PORTVERSION=	3.12.2
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window and compositing manager based on Clutter

BUILD_DEPENDS=	zenity3>=3.0.0:${PORTSDIR}/x11/zenity3 \
		gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libclutter-1.0.so:${PORTSDIR}/graphics/clutter \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libupower-glib.so:${PORTSDIR}/sysutils/upower
RUN_DEPENDS=	zenity3>=3.0.0:${PORTSDIR}/x11/zenity3 \
		gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gnomehier gnomeprefix gtk30 intlhack \
		introspection:build
USE_XORG=	x11 xext xrandr xcomposite xcursor xinerama ice sm xfixes \
		xrender xdamage
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -fno-omit-frame-pointer
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-compile-warnings=maximum
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.gnome.mutter.gschema.xml

PLIST_SUB=	VERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e 's|-Wcast-align||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
