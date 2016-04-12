# $FreeBSD$

PORTNAME=	compiz
PORTVERSION=	0.8.8
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Compiz Composite/Window Manager

LIB_DEPENDS=	libpng.so:graphics/png \
		libgtop-2.0.so:devel/libgtop \
		libstartup-notification-1.so:x11/startup-notification
RUN_DEPENDS=	glxinfo:graphics/mesa-demos \
		nvidia-settings:x11/nvidia-settings

XORG_CAT=	app
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gettext gmake libtool pathfix tar:bzip2
USE_GL=		glu
USE_GNOME=	gconf2 libxslt intltool
USE_XORG=	glproto ice sm x11 xcomposite xdamage xext xfixes xinerama \
		xrandr xrender
USE_LDCONFIG=	yes

GCONF_SCHEMAS=	gwd.schemas \
		compiz-annotate.schemas \
		compiz-blur.schemas \
		compiz-clone.schemas \
		compiz-commands.schemas \
		compiz-core.schemas \
		compiz-cube.schemas \
		compiz-dbus.schemas \
		compiz-decoration.schemas \
		compiz-fade.schemas \
		compiz-fs.schemas \
		compiz-gconf.schemas \
		compiz-glib.schemas \
		compiz-gnomecompat.schemas \
		compiz-ini.schemas \
		compiz-inotify.schemas \
		compiz-kconfig.schemas \
		compiz-minimize.schemas \
		compiz-move.schemas \
		compiz-obs.schemas \
		compiz-place.schemas \
		compiz-png.schemas \
		compiz-regex.schemas \
		compiz-resize.schemas \
		compiz-rotate.schemas \
		compiz-scale.schemas \
		compiz-screenshot.schemas \
		compiz-svg.schemas \
		compiz-switcher.schemas \
		compiz-video.schemas \
		compiz-water.schemas \
		compiz-wobbly.schemas \
		compiz-zoom.schemas

CONFIGURE_ARGS=	--disable-kde4 --disable-kde \
		--disable-gnome --disable-gnome-keybindings
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	SVG GTK2 METACITY DBUS FUSE
OPTIONS_DEFAULT=	SVG GTK2 METACITY DBUS

METACITY_DESC=	Enable Metacity support

SUB_FILES=		compiz-manager
DESKTOP_ENTRIES=	"Compiz Manager" \
			"Wrapper script for starting compiz" \
			"" \
			"compiz-manager" \
			"System;Core;" \
			false

OPTIONS_SUB=	yes
SVG_CONFIGURE_ENABLE=	librsvg
SVG_USE=	GNOME=librsvg2

GTK2_CONFIGURE_ENABLE=	gtk
GTK2_USE=	GNOME=glib20,libwnck

FUSE_CONFIGURE_ENABLE=	fuse
FUSE_USES=		fuse

.include <bsd.port.options.mk>

.if !empty(PORT_OPTIONS:MMETACITY) && !empty(PORT_OPTIONS:MGNOME) && !empty(PORT_OPTIONS:MGTK2)
CONFIGURE_ARGS+=	--enable-metacity
USE_GNOME+=	metacity
.else
CONFIGURE_ARGS+=	--disable-metacity
.endif

.if ${PORT_OPTIONS:MDBUS}
CONFIGURE_ARGS+=	--enable-dbus
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus
.if ${PORT_OPTIONS:MGTK2} && ${PORT_OPTIONS:MGNOME}
CONFIGURE_ARGS+=	--enable-dbus-glib
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:devel/dbus-glib
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:devel/dbus-glib
.endif
.else
CONFIGURE_ARGS+=	--disable-dbus --disable-dbus-glib
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/compiz-manager ${STAGEDIR}${PREFIX}/bin/compiz-manager

.include <bsd.port.mk>
