# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-panel
PORTVERSION=	1.12.2
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the MATE Desktop

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libcanberra-gtk.so:audio/libcanberra

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig python tar:xz
USE_MATE=	desktop libmateweather  menus
USE_XORG=	ice sm x11 xau xrandr
USE_GNOME=	cairo dconf gdkpixbuf2 glib20 gtk20 \
		intlhack introspection:build librsvg2 pango libwnck
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-network-manager \
		--disable-gtk-doc \
		--with-gtk=2.0 \
		--with-html-dir=${PREFIX}/share/doc \
		--libexecdir=${PREFIX}/lib/mate-panel
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.panel.applet.clock.gschema.xml \
		org.mate.panel.applet.fish.gschema.xml \
		org.mate.panel.applet.window-list.gschema.xml \
		org.mate.panel.applet.workspace-switcher.gschema.xml \
		org.mate.panel.enums.xml \
		org.mate.panel.gschema.xml \
		org.mate.panel.menubar.gschema.xml \
		org.mate.panel.object.gschema.xml \
		org.mate.panel.toplevel.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mate-panel/modules

.include <bsd.port.mk>
