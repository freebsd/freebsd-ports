# New ports collection makefile for:	compiz
# Date created:				Dec 20 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	compiz
PORTVERSION=	0.5.0
#PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	rnoland@2hip.net
COMMENT=	Compiz Composite/Window Manager

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	${BUILD_DEPENDS}

XORG_CAT=	app
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GL=		glu
USE_GNOME=	gnomehack gnomeprefix gconf2
USE_XORG=	xcomposite xfixes xdamage xrandr xrender ice sm xinerama glproto
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	compiz.schemas gwd.schemas
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	RSVG "Enable librsvg2 support" on \
		GTK "Enable gtk2 support" on \
		METACITY "Enable Metacity support" on \
		GNOME "Enable Gnome support" on \
		DBUS "Enable DBUS support" on \
		FUSEFS "Enable fusefs support" off

# No KDE support for now...
CONFIGURE_ARGS=	--disable-kde

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng12|' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if defined(WITH_RSVG)
CONFIGURE_ARGS+=	--enable-librsvg
USE_GNOME+=		librsvg2
PLIST_SUB+=		RSVG=""
.else
CONFIGURE_ARGS+=	--disable-librsvg
PLIST_SUB+=		RSVG="@comment "
.endif

.if defined(WITH_METACITY) || defined(WITH_GTK) || defined(WITH_GNOME)
CONFIGURE_ARGS+=	--enable-gtk
USE_GNOME+=	 glib20 libwnck
PLIST_SUB+=	GTK=""
.else
CONFIGURE_ARGS+=	--disable-gtk
PLIST_SUB+=	GTK="@comment "
.endif

.if defined(WITH_METACITY) || defined(WITH_GNOME)
CONFIGURE_ARGS+=	--enable-metacity
USE_GNOME+=	metacity
.else
CONFIGURE_ARGS+=	--disable-metacity
.endif

.if defined(WITH_GNOME)
CONFIGURE_ARGS+=	--enable-gnome
USE_GNOME+=	 gnomecontrolcenter2
WINDOWSETTINGSDATADIR=	\
		`pkg-config --variable=prefix gnome-window-settings-2.0`
WINDOWSETTINGSLIBDIR=	\
		`pkg-config --variable=libdir gnome-window-settings-2.0`
PLIST_SUB+=	GNOME="" \
		WINDOWSETTINGSDATADIR="${WINDOWSETTINGSDATADIR}" \
		WINDOWSETTINGSLIBDIR="${WINDOWSETTINGSLIBDIR}"
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=	GNOME="@comment "
.endif

.if defined(WITH_DBUS)
CONFIGURE_ARGS+=	--enable-dbus
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus
.if defined(WITH_GTK) || defined(WITH_GNOME)
CONFIGURE_ARGS+=	--enable-dbus-glib
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib
.endif
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=	--disable-dbus --disable-dbus-glib
PLIST_SUB+=	DBUS="@comment "
.endif

.if defined(WITH_FUSEFS)
CONFIGURE_ARGS+=	--enable-fuse
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/fuse.pc:${PORTSDIR}/sysutils/fusefs-libs
PLIST_SUB+=		FUSEFS=""
.else
CONFIGURE_ARGS+=	--disable-fuse
PLIST_SUB+=		FUSEFS="@comment "
.endif

.include <bsd.port.post.mk>
