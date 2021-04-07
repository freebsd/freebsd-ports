PORTNAME=	remontoire
DISTVERSION=	1.4.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Keybinding viewer for i3 and other programs

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext-tools gnome meson pkgconfig python:build shebangfix
USE_GITHUB=	yes
USE_GNOME=	gtk30
GH_ACCOUNT=	regolith-linux
SHEBANG_FILES=	build-aux/meson/postinstall.py
PLIST_FILES=	bin/${PORTNAME} \
		share/appdata/org.regolith-linux.remontoire.appdata.xml \
		share/applications/org.regolith-linux.remontoire.desktop
GLIB_SCHEMAS=	org.regolith-linux.remontoire.gschema.xml

.include <bsd.port.mk>
