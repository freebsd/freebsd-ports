PORTNAME=	budgie-screensaver
DISTVERSION=	5.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	x11 budgie
MASTER_SITES=	BUDGIE

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Budgie screen saver and locker
WWW=		https://github.com/BuddiesOfBudgie/budgie-screensaver

LICENSE=	GPLv2

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus
RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		gjs>0:lang/gjs \
		gnome-keyring>0:security/gnome-keyring

USES=		budgie gettext gnome meson pkgconfig tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 gnomedesktop3 intltool \
		libgnomekbd
USE_XORG=	x11 xxf86vm

SUB_FILES=	budgie-screensaver

MESON_ARGS=	-Dwith-systemd=false \
		-Dwith-console-kit=true

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${LOCALBASE}|g' \
		${WRKSRC}/src/gnome-screensaver.c
	${REINPLACE_CMD} -e 's|/etc/pam.d|${LOCALBASE}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c

post-install:
#	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pam.d
	${INSTALL_DATA} ${WRKDIR}/budgie-screensaver \
		${STAGEDIR}${PREFIX}/etc/pam.d

.include <bsd.port.mk>
