# $FreeBSD$

PORTNAME=	compiz
PORTVERSION=	0.8.4
PORTREVISION=	9
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiz Composite/Window Manager

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	glxinfo:${PORTSDIR}/graphics/mesa-demos \
		nvidia-settings:${PORTSDIR}/x11/nvidia-settings

XORG_CAT=	app
GNU_CONFIGURE=	yes
USES=		gettext pathfix gmake tar:bzip2
USE_GL=		glu
USE_GNOME=	gconf2 libxslt
USE_XORG=	xcomposite xfixes xdamage xrandr xrender ice sm xinerama glproto
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

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

CONFIGURE_ARGS=	--disable-kde4
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	SVG GTK2 METACITY GNOME DBUS FUSE
OPTIONS_DEFAULT=	SVG GTK2 METACITY GNOME DBUS

METACITY_DESC=	Enable Metacity support

SUB_FILES=		compiz-manager
DESKTOP_ENTRIES=	"Compiz Manager" \
			"Wrapper script for starting compiz" \
			"" \
			"compiz-manager" \
			"System;Core;" \
			false

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng15|' -e 's|gnome-desktop-2.0|gnome-desktop-2.0 gconf-2.0|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/compiz-manager ${PREFIX}/bin/compiz-manager
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSVG}
CONFIGURE_ARGS+=	--enable-librsvg
USE_GNOME+=		librsvg2
PLIST_SUB+=		RSVG=""
.else
CONFIGURE_ARGS+=	--disable-librsvg
PLIST_SUB+=		RSVG="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	--enable-gtk
USE_GNOME+=	 glib20 libwnck
PLIST_SUB+=	GTK2=""
.else
CONFIGURE_ARGS+=	--disable-gtk
PLIST_SUB+=	GTK2="@comment "
.endif

.if !empty(PORT_OPTIONS:MMETACITY) && !empty(PORT_OPTIONS:MGNOME) && !empty(PORT_OPTIONS:MGTK2)
CONFIGURE_ARGS+=	--enable-metacity
USE_GNOME+=	metacity
.else
CONFIGURE_ARGS+=	--disable-metacity
.endif

.if ${PORT_OPTIONS:MGNOME} && ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	--enable-gnome \
			--enable-gnome-keybindings
USE_GNOME+=	 gnomecontrolcenter2
WINDOWSETTINGSDATADIR=	\
		`pkg-config --variable=prefix gnome-window-settings-2.0`
WINDOWSETTINGSLIBDIR=	\
		`pkg-config --variable=libdir gnome-window-settings-2.0`
PLIST_SUB+=	GNOME="" \
		WINDOWSETTINGSDATADIR="${WINDOWSETTINGSDATADIR}" \
		WINDOWSETTINGSLIBDIR="${WINDOWSETTINGSLIBDIR}"
.else
CONFIGURE_ARGS+=	--disable-gnome \
			--disable-gnome-keybindings
PLIST_SUB+=	GNOME="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
CONFIGURE_ARGS+=	--enable-dbus
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus
.if ${PORT_OPTIONS:MGTK} && ${PORT_OPTIONS:MGNOME}
CONFIGURE_ARGS+=	--enable-dbus-glib
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib
.endif
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=	--disable-dbus --disable-dbus-glib
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MFUSE}
CONFIGURE_ARGS+=	--enable-fuse
USES+=			fuse
PLIST_SUB+=		FUSE=""
.else
CONFIGURE_ARGS+=	--disable-fuse
PLIST_SUB+=		FUSE="@comment "
.endif

CONFIGURE_ARGS+=	--disable-kde
PLIST_SUB+=	KDE3="@comment "

.include <bsd.port.post.mk>
