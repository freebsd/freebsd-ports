# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-wm
PORTVERSION=	4.10.1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/xfwm4/${PORTVERSION:R}
DISTNAME=	xfwm4-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's window manager

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libwnck-1.so:${PORTSDIR}/x11-toolkits/libwnck

CONFIGURE_ARGS=	--enable-xsync \
		--enable-render \
		--enable-randr \
		--disable-kde-systray
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USES=		pathfix pkgconfig gmake
USE_GNOME=	gtk20 intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	configenv libmenu libutil xfconf
USE_XORG=	x11 sm xext xrandr xrender
DATADIR=	${PREFIX}/share/xfwm4

OPTIONS_DEFINE=		COMPOSITE NLS NOTIFY REVMOUSE
OPTIONS_DEFAULT=	COMPOSITE NOTIFY
REVMOUSE_DESC=		Reverse mouse workspace changing direction

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPOSITE}
CONFIGURE_ARGS+=--enable-compositor
.else
CONFIGURE_ARGS+=--disable-compositor
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if ${PORT_OPTIONS:MREVMOUSE}
EXTRA_PATCHES=	${FILESDIR}/extrapatch-src__events.c
.endif

.include <bsd.port.mk>
