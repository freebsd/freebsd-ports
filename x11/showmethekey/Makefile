PORTNAME=	showmethekey
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.6
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Show keys you typed on screen

LICENSE=	APACHE20

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libevdev.so:devel/libevdev \
		libudev.so:devel/libudev-devd \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	pkexec:sysutils/polkit

USES=		compiler:c11 gettext-tools gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gtk30
GH_ACCOUNT=	AlynxZhou
PLIST_FILES=	bin/${PORTNAME}-cli \
		bin/${PORTNAME}-gtk \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/locale/zh_CN/LC_MESSAGES/${PORTNAME}.mo \
		share/pixmaps/${PORTNAME}.png
GLIB_SCHEMAS=	one.alynx.showmethekey.gschema.xml
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
