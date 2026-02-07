PORTNAME=	budgie-session
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	x11 budgie
MASTER_SITES=	BUDGIE

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Session manager for the Budgie desktop
WWW=		https://github.com/BuddiesOfBudgie/budgie-session

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlto:textproc/xmlto
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libdbus-glib-1.so:devel/dbus-glib \
		libepoxy.so:graphics/libepoxy
RUN_DEPENDS=	consolekit2>0:sysutils/consolekit2

USES=		budgie compiler:c11 gettext-tools gl gnome localbase:ldflags \
		meson pkgconfig python:build shebangfix tar:xz xorg
USE_GL=		egl gl glesv2
USE_GNOME=	gnomedesktop3 glib20 gtk30 libxslt:build
GLIB_SCHEMAS=	org.buddiesofbudgie.SessionManager.gschema.xml
USE_XORG=	ice sm x11 xcomposite xtrans
SHEBANG_FILES=	meson_post_install.py

MESON_ARGS=	-Dsystemd=false \
		-Dsystemd_journal=false \
		-Dconsolekit=true

.include <bsd.port.mk>
