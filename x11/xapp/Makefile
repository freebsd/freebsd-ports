# $FreeBSD$

PORTNAME=	xapp
PORTVERSION=	2.0.4
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cross-desktop libraries and common resources

LICENSE=	LGPL3
LICENSE_FILE?=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libxklavier.so:x11/libxklavier \
		libdbusmenu-gtk3.so:devel/libdbusmenu
RUN_DEPENDS=	bash:shells/bash

USES=		gettext-tools:build gnome meson pkgconfig python:3.5+ \
		shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_FILES=	data libxapp meson-scripts schemas scripts status-applets \
		test-scripts
BINARY_ALIAS=	python3=${PYTHON_CMD}

USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 introspection intltool \
		libgnomekbd pygobject3

GLIB_SCHEMAS=	org.x.apps.gschema.xml
INSTALLS_ICONS=	yes

USE_XORG=	x11

USE_LDCONFIG=	yes

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

.include <bsd.port.mk>
