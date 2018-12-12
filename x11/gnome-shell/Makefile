# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell
PORTVERSION=	3.28.3
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		sassc:textproc/sassc \
		gnome-control-center:sysutils/gnome-control-center
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libdrm.so:graphics/libdrm \
		libmutter-2.so:x11-wm/mutter \
		libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libsecret-1.so:security/libsecret \
		libpolkit-agent-1.so:sysutils/polkit \
		libp11-kit.so:security/p11-kit \
		libical.so:devel/libical \
		libgcr-3.so:security/gcr \
		libicuuc.so:devel/icu \
		libpulse.so:audio/pulseaudio \
		libcroco-0.6.so:textproc/libcroco \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libp11-kit.so:security/p11-kit \
		libgjs.so:lang/gjs
RUN_DEPENDS=	gnome-control-center:sysutils/gnome-control-center

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 cpe gettext gl gnome libtool localbase meson \
		pathfix perl5 pkgconfig python:3.4+ shebangfix tar:xz webplugin:native
USE_GNOME=	cairo evolutiondataserver3 gdkpixbuf2 introspection \
		libxslt:build libxml2
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr xtst
USE_GL=		egl gbm
USE_GSTREAMER1=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes
SHEBANG_FILES=	src/gnome-shell-perf-tool.in \
		src/gnome-shell-extension-tool.in

WEBPLUGIN_NAME=	libgnome-shell-browser-plugin.so
WEBPLUGIN_DIR=	${PREFIX}/lib/mozilla/plugins/
WEBPLUGIN_FILES=libgnome-shell-browser-plugin.so

MESON_ARGS=	-Dsystemd=false \
		-Dnetworkmanager=false
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.shell.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_VERSION}|g' \
		${WRKSRC}/meson.build
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|g' \
		${WRKSRC}/src/shell-app-system.c

pre-build:
	@cd ${BUILD_WRKSRC} && ninja src/st/st-scroll-view-fade-generated.c

.include <bsd.port.mk>
