# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-panel
PORTVERSION=	1.6.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the MATE Desktop

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	desktop docutils libmateweather libmatewnck menus
USE_XORG=	ice sm x11 xau xrandr
USE_GNOME=	cairo dconf gdkpixbuf2 glib20 gnomehier gtk20 \
		intlhack introspection:build librsvg2 ltverhack pango
USE_PYTHON=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-network-manager \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc \
		--libexecdir=${PREFIX}/lib/mate-panel
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

GLIB_SCHEMAS=	org.mate.panel.applet.clock.gschema.xml \
		org.mate.panel.applet.fish.gschema.xml \
		org.mate.panel.applet.window-list.gschema.xml \
		org.mate.panel.applet.workspace-switcher.gschema.xml \
		org.mate.panel.enums.xml \
		org.mate.panel.gschema.xml \
		org.mate.panel.object.gschema.xml \
		org.mate.panel.toplevel.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mate-panel/modules
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/libmate-panel-applet-4.so.1

.include <bsd.port.mk>
