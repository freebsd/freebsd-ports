# Created by: Pawel Worach <pawel.worach@gmail.com>

PORTNAME=	gnome-shell
PORTVERSION=	41.3
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	65450a836ee9.patch:-p1 # https://gitlab.gnome.org/GNOME/gnome-shell/-/merge_requests/2078

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/bash-completion/bash_completion.sh:shells/bash-completion \
		a2x:textproc/asciidoc \
		docbook-xsl>=0:textproc/docbook-xsl \
		gnome-control-center:sysutils/gnome-control-center \
		sassc:textproc/sassc
LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libcroco-0.6.so:textproc/libcroco \
		libdrm.so:graphics/libdrm \
		libgcr-base-3.so:security/gcr \
		libgjs.so:lang/gjs \
		libgnome-autoar-0.so:archivers/gnome-autoar \
		libgraphene-1.0.so:graphics/graphene \
		libical.so:devel/libical \
		libicuuc.so:devel/icu \
		libjson-glib-1.0.so:devel/json-glib \
		libmutter-9.so:x11-wm/mutter \
		libp11-kit.so:security/p11-kit \
		libpolkit-agent-1.so:sysutils/polkit \
		libpulse.so:audio/pulseaudio \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libstartup-notification-1.so:x11/startup-notification
RUN_DEPENDS=	gdm:x11/gdm \
		gkbd-keyboard-display:x11/libgnomekbd \
		gnome-control-center:sysutils/gnome-control-center

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 cpe gettext gl gnome libtool localbase meson \
		pathfix perl5 pkgconfig python:3.4+ shebangfix tar:xz \
		webplugin:native xorg
USE_GNOME=	cairo evolutiondataserver3 gdkpixbuf2 gnomedesktop3 gtk40 \
		introspection libxml2 libxslt:build
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr xtst
USE_GL=		egl gbm
USE_GSTREAMER1=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes
SHEBANG_FILES=	src/gnome-shell-extension-tool.in src/gnome-shell-perf-tool.in
BINARY_ALIAS=	python3=${PYTHON_CMD}

WEBPLUGIN_NAME=	libgnome-shell-browser-plugin.so
WEBPLUGIN_DIR=	${PREFIX}/lib/mozilla/plugins/
WEBPLUGIN_FILES=	libgnome-shell-browser-plugin.so

MESON_ARGS=	-Dnetworkmanager=false \
		-Dsystemd=false \
		-Dtests=false
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	00_org.gnome.shell.gschema.override \
		org.gnome.shell.gschema.xml

post-extract:
	${CP} ${FILESDIR}/*.xml ${WRKSRC}/data/dbus-interfaces

post-patch:
	${REINPLACE_CMD} -e "s,python3,${PYTHON_VERSION},g" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
