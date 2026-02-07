PORTNAME=	remontoire
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.4
CATEGORIES=	x11

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Keybinding viewer for i3 and other programs
WWW=		https://github.com/regolith-linux/remontoire

LICENSE=	GPLv3

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libjson-glib-1.0.so:devel/json-glib

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig \
		python:build shebangfix vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	regolith-linux
USE_GNOME=	gtk30
GLIB_SCHEMAS=	org.regolith-linux.remontoire.gschema.xml

SHEBANG_FILES=	build-aux/meson/postinstall.py

PLIST_FILES=	bin/${PORTNAME} \
		share/appdata/org.regolith-linux.remontoire.appdata.xml \
		share/applications/org.regolith-linux.remontoire.desktop

.include <bsd.port.mk>
