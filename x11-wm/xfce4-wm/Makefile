# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-wm
PORTVERSION=	4.12.3
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE/src/xfce/xfwm4/${PORTVERSION:R}
DISTNAME=	xfwm4-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's window manager

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

CONFIGURE_ARGS=	--enable-xsync \
		--enable-render \
		--enable-randr \
		--enable-compositor \
		--disable-kde-systray
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		pkgconfig gmake gettext-tools xfce tar:bzip2
USE_GNOME=	gtk20 intltool intlhack libwnck
USE_LDCONFIG=	yes
USE_XFCE=	libmenu
USE_XORG=	x11 sm xcomposite xdamage xext xfixes xrandr xrender
DATADIR=	${PREFIX}/share/xfwm4

OPTIONS_DEFINE=		DRM NLS STARTUP
OPTIONS_DEFAULT=	STARTUP
DRM_DESC=	Direct Rendering Module service
STARTUP_DESC=	Startup notification
DRM_LIB_DEPENDS=	libdrm.so:graphics/libdrm
DRM_CONFIGURE_ENABLE=	libdrm
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
STARTUP_CONFIGURE_ENABLE=	startup-notification
OPTIONS_SUB=	yes

.include <bsd.port.mk>
