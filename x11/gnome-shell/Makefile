PORTNAME=	gnome-shell
PORTVERSION=	47.8
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell
WWW=		https://gitlab.gnome.org/GNOME/gnome-shell

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		sassc:textproc/sassc

LIB_DEPENDS=	libgcr-4.so:security/gcr \
		libgjs.so:lang/gjs \
		libgraphene-1.0.so:graphics/graphene \
		libical.so:devel/libical \
		libjson-glib-1.0.so:devel/json-glib \
		libmutter-15.so:x11-wm/mutter \
		libp11-kit.so:security/p11-kit \
		libpolkit-agent-1.so:sysutils/polkit \
		libpulse-mainloop-glib.so:audio/pulseaudio \
		libpipewire-0.3.so:multimedia/pipewire \
		libibus-1.0.so:textproc/ibus

RUN_DEPENDS=	gdm:x11/gdm \
		tecla:x11/tecla

USES=		compiler:c11 cpe gettext-tools gnome gstreamer localbase \
		meson pathfix pkgconfig python:build shebangfix tar:xz xorg
CPE_VENDOR=	gnome
USE_GNOME=	atk evolutiondataserver3 gdkpixbuf glib20 \
		gnomedesktop4 gnomecontrolcenter3 gtk40 introspection \
		libxml2 libxslt:build
USE_XORG=	x11 xfixes

PORTSCOUT=	limit:^47\.

SHEBANG_FILES=	src/gnome-shell-test-tool.in \
		src/data-to-c.py
# These libs are found via rpath mechanism
NO_SHLIB_REQUIRES_GLOB=	libmutter-clutter-* libmutter-cogl-* libmutter-mtk-*

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

EXAMPLES_SUB_FILES=	pkg-message xprofile

MESON_ARGS=	-Dnetworkmanager=false \
		-Dportal_helper=false \
		-Dsystemd=false \
		-Dtests=false \
		-Dextensions_tool=false

GLIB_SCHEMAS=	00_org.gnome.shell.gschema.override \
		org.gnome.shell.gschema.xml \
		org.gnome.Extensions.gschema.xml

post-extract:
	@${CP} ${FILESDIR}/*.xml ${WRKSRC}/data/dbus-interfaces

post-patch:
	@${REINPLACE_CMD} -e "s,python3,${PYTHON_VERSION},g" \
		${WRKSRC}/meson.build

pre-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

post-install-EXAMPLES-on:
	@${INSTALL_SCRIPT} ${WRKDIR}/xprofile ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
