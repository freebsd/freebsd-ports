PORTNAME=	gnome-shell-extensions
PORTVERSION=	47.6
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME desktop shell extensions
WWW=		https://apps.gnome.org/Extensions/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgjs.so:lang/gjs
RUN_DEPENDS=	gnome-shell>=47.0:x11/gnome-shell \
		libgtop>0:devel/libgtop \
		gnome-menus>0:x11/gnome-menus

NO_ARCH=	yes
USES=		gettext-tools gnome meson pkgconfig python tar:xz
USE_GNOME=	glib20

PORTSCOUT=	limit:^47\.

MESON_ARGS=	-Dclassic_mode=true
BINARY_ALIAS=	python3=${PYTHON_CMD}

SUB_FILES=	pkg-message
SUB_LIST=	EXAMPLESDIR=${EXAMPLESDIR:S|${PORTNAME}|gnome-shell|}

GLIB_SCHEMAS=	00_org.gnome.shell.extensions.classic.gschema.override \
		org.gnome.shell.extensions.apps-menu.gschema.xml \
		org.gnome.shell.extensions.screenshot-window-sizer.gschema.xml \
		org.gnome.shell.extensions.window-list.gschema.xml \
		org.gnome.shell.extensions.workspace-indicator.gschema.xml

.include <bsd.port.mk>
