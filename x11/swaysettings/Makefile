PORTNAME=	swaysettings
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GUI for setting Sway wallpaper, default apps, GTK themes, etc.
WWW=		https://github.com/ErikReider/SwaySettings

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libjson-glib-1.0.so:devel/json-glib \
		libgee-0.8.so:devel/libgee \
		libgtop-2.0.so:devel/libgtop \
		libaccountsservice.so:sysutils/accountsservice \
		libudisks2.so:sysutils/libudisks \
		libgtk4-layer-shell.so:x11-toolkits/gtk4-layer-shell

USES=		compiler:c11 gettext gnome meson pkgconfig \
		python:build shebangfix vala:build
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf gtk40 libadwaita libxml2
GH_ACCOUNT=	ErikReider
GH_PROJECT=	SwaySettings
SHEBANG_FILES=	build-aux/meson/postinstall.py
GLIB_SCHEMAS=	org.erikreider.swaysettings.gschema.xml

post-patch:
# Respect PREFIX for images and XKB layouts
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/src/Settings/Page/InputPage.vala \
		${WRKSRC}/src/Settings/Pages/Background/BackgroundPage.vala \
		${WRKSRC}/src/Settings/Pages/Users/Users.vala
# Drop unused dependency
	@${REINPLACE_CMD} -e 's/granite-7/gio-unix-2.0/' \
		${WRKSRC}/src/meson.build
# Disable Linux-only bluez and rfkill
	@${REINPLACE_CMD} -e '/Bluetooth/d; /Rfkill/d' \
		${WRKSRC}/src/Settings/meson.build \
		${WRKSRC}/src/Settings/Pages/meson.build \
		${WRKSRC}/data/swaysettings.gresource.xml
	@${REINPLACE_CMD} -e '/bluetooth-symbolic/d' \
		-e 's/new BluetoothPage.*/null;/' \
		${WRKSRC}/src/Settings/Window/Window.vala

.include <bsd.port.mk>
