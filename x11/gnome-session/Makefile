PORTNAME=	gnome-session
PORTVERSION=	47.0.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME desktop
WWW=		https://gitlab.gnome.org/GNOME/gnome-session

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	xmlto:textproc/xmlto
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libdbus-glib-1.so:devel/dbus-glib \
		libepoxy.so:graphics/libepoxy
RUN_DEPENDS=	consolekit2>0:sysutils/consolekit2 \
		dbus-daemon:devel/dbus \
		zenity:x11/zenity

USES=		compiler:c11 gettext gl gnome localbase:ldflags meson \
		pkgconfig python:build tar:xz xorg
USE_GNOME=	glib20 gnomedesktop3 gtk30 libxslt:build
USE_XORG=	ice sm x11 xcomposite xtrans
USE_GL=		egl gl glesv2
MESON_ARGS=	-Ddocbook=false \
		-Dsystemd=false \
		-Dsystemd_session=disable \
		-Dsystemd_journal=false \
		-Dconsolekit=true
BINARY_ALIAS=	python3=${PYTHON_VERSION}

PLIST_SUB=	VERSION=${PORTVERSION:C/^([0-9]+)\..*/\1/}

GLIB_SCHEMAS=	org.gnome.SessionManager.gschema.xml

post-patch:
# Avoid lots of warnings in gdm log
.for f in gnome-wayland.desktop.in.in gnome.desktop.in.in
	${REINPLACE_CMD} -e 's|/gnome-session|/gnome-session --disable-acceleration-check|g' \
		${WRKSRC}/data/${f}
.endfor 

.include <bsd.port.mk>
