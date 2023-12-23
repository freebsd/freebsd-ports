PORTNAME=	swaysettings
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GUI for setting Sway wallpaper, default apps, GTK themes, etc.
WWW=		https://github.com/ErikReider/SwaySettings

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libjson-glib-1.0.so:devel/json-glib \
		libgee-0.8.so:devel/libgee \
		libaccountsservice.so:sysutils/accountsservice \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell \
		libhandy-1.so:x11-toolkits/libhandy

USES=		compiler:c11 gettext gnome localbase:ldflags meson pkgconfig \
		python:build shebangfix vala:build
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 libxml2
GH_ACCOUNT=	ErikReider
GH_PROJECT=	SwaySettings
SHEBANG_FILES=	build-aux/meson/postinstall.py
GLIB_SCHEMAS=	org.erikreider.swaysettings.gschema.xml

post-patch:
# Respect PREFIX for images and XKB layouts
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/src/Page/Input_Page.vala \
		${WRKSRC}/src/Pages/Background/Background_Page.vala \
		${WRKSRC}/src/Pages/Users/Users.vala
# Drop unused dependency
	@${REINPLACE_CMD} -e 's/granite/gio-unix-2.0/' \
		${WRKSRC}/src/meson.build
# Disable Linux-only bluez and rfkill
	@${REINPLACE_CMD} -e '/Bluetooth/d; /Rfkill/d' \
		${WRKSRC}/src/meson.build \
		${WRKSRC}/src/${PORTNAME}.gresource.xml
	@${REINPLACE_CMD} -e '/bluetooth-symbolic/d' \
		-e 's/new Bluetooth_Page.*/null;/' \
		${WRKSRC}/src/Window/Window.vala

post-configure:
# XXX https://github.com/ErikReider/SwaySettings/issues/36
	@${REINPLACE_CMD} -e '/pkg/s/accountsservice/AccountsService-1.0/' \
		${BUILD_WRKSRC}/build.ninja

.include <bsd.port.mk>
