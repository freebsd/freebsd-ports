PORTNAME=	xapp
PORTVERSION=	2.2.12
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cross-desktop libraries and common resources

LICENSE=	LGPL3
LICENSE_FILE?=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libdbusmenu-gtk3.so:devel/libdbusmenu
RUN_DEPENDS=	bash:shells/bash

USES=		gettext-tools gnome meson pkgconfig python shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk-update-icon-cache gtk30 \
		intltool introspection:build libgnomekbd pygobject3
USE_LDCONFIG=	yes
USE_XORG=	x11
GLIB_SCHEMAS=	org.x.apps.gschema.xml
SHEBANG_FILES=	data libxapp meson-scripts schemas scripts status-applets \
		test-scripts

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_ON=		-Ddocs=true

.include <bsd.port.mk>
