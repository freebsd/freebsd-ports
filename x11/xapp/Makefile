PORTNAME=	xapp
DISTVERSION=	2.8.9
PORTREVISION=	1
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cross-desktop libraries and common resources
WWW=		https://github.com/linuxmint/xapp

LICENSE=	LGPL3
LICENSE_FILE?=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libdbusmenu-gtk3.so:devel/libdbusmenu
RUN_DEPENDS=	bash:shells/bash

USES=		gettext-tools gnome meson pkgconfig python shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libgnomekbd
USE_LDCONFIG=	yes
USE_XORG=	x11
GLIB_SCHEMAS=	org.x.apps.gschema.xml
SHEBANG_FILES=	data schemas scripts status-applets test-scripts

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		DOCS INTROSPECTION MATE STATUS VAPI XFCE
OPTIONS_DEFAULT=	INTROSPECTION MATE STATUS VAPI XFCE
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

INTROSPECTION_DESC=	Enable GObject introspection
INTROSPECTION_MESON_TRUE=	introspection
INTROSPECTION_USE=		GNOME=pygobject3,introspection:build

MATE_DESC=		Install mate specific items
MATE_MESON_TRUE=	mate

STATUS_DESC=		Build the XApp StatusNotifier service
STATUS_MESON_TRUE=	status-notifier

VAPI_DESC=		Enable Vala bindings
VAPI_MESON_TRUE=	vapi
VAPI_USES=		vala:build
VAPI_IMPLIES=		INTROSPECTION

XFCE_DESC=		Install xfce specific items
XFCE_MESON_TRUE=	xfce

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|g' \
		${WRKSRC}/scripts/upload-system-info

.include <bsd.port.mk>
