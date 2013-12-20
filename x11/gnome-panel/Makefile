# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-panel/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	gnome-panel
PORTVERSION=	3.6.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the GNOME 3 Desktop

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgweather-3.so:${PORTSDIR}/net/libgweather \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon

USES=		gettext gmake pathfix pkgconfig
USE_XORG=	ice sm x11 xau xrandr
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 librsvg2 libwnck3 \
		gnomemenus3 ltverhack referencehack
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-network-manager
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-panel.applet.clock.gschema.xml \
		org.gnome.gnome-panel.applet.fish.gschema.xml \
		org.gnome.gnome-panel.applet.window-list.gschema.xml \
		org.gnome.gnome-panel.applet.workspace-switcher.gschema.xml \
		org.gnome.gnome-panel.enums.xml \
		org.gnome.gnome-panel.gschema.xml \
		org.gnome.gnome-panel.launcher.gschema.xml \
		org.gnome.gnome-panel.menu-button.gschema.xml \
		org.gnome.gnome-panel.object.gschema.xml \
		org.gnome.gnome-panel.toplevel.gschema.xml

#OPTIONS_DEFINE=	EVOLUTION
#OPTIONS_DEFAULT=EVOLUTION
#EVOLUTION_DESC=	Evolution calendar support

.include <bsd.port.options.mk>

#.if ${PORT_OPTIONS:MEVOLUTION}
#USE_GNOME+=	evolutiondataserver3
#CONFIGURE_ARGS+=--enable-eds
#.else
CONFIGURE_ARGS+=--disable-eds
#.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|"applications.menu"|"gnome-applications.menu"|'
	@${REINPLACE_CMD} -e 's|xsltproc -o| xsltproc --nonet -o|g' \
		${WRKSRC}/help/clock/Makefile.in \
		${WRKSRC}/help/fish/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpanel-applet-4.so.0

.include <bsd.port.mk>

.endif
