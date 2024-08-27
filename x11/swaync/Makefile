PORTNAME=	swaync
DISTVERSIONPREFIX=	v
PORTVERSION=	0.12.2
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Wayland notification daemon with GTK panel
WWW=		https://github.com/ErikReider/SwayNotificationCenter

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler \
		sassc:textproc/sassc
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libgee-0.8.so:devel/libgee \
		libgraphene-1.0.so:graphics/graphene \
		libwayland-client.so:graphics/wayland \
		libgranite-7.so:x11-toolkits/granite7 \
		libgtk4-layer-shell.so:x11-toolkits/gtk4-layer-shell

USES=		compiler:c11 gnome meson pkgconfig \
		python:build shebangfix vala:build
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk40 libadwaita
GH_ACCOUNT=	ErikReider
GH_PROJECT=	SwayNotificationCenter
SHEBANG_FILES=	build-aux/meson/postinstall.py
GLIB_SCHEMAS=	org.erikreider.swaync.gschema.xml

OPTIONS_DEFINE=	MANPAGES PULSEAUDIO
OPTIONS_DEFAULT=MANPAGES PULSEAUDIO

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_TRUE=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man1/${PORTNAME}-client.1.gz \
			share/man/man5/${PORTNAME}.5.gz

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_TRUE=	pulse-audio

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/src/meson.build
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e "s,'/',get_option('prefix')," \
		-e "/output.*json/s/'[^']*/&.sample/" \
		${WRKSRC}/src/meson.build
	@${REINPLACE_CMD} -e "s,'/',get_option('prefix')," \
		-e "/output.*css/s/'[^']*/&.sample/" \
		${WRKSRC}/data/meson.build
# Respect PREFIX in manpages
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/man/${PORTNAME}.1.scd

.include <bsd.port.mk>
