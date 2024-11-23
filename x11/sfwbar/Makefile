PORTNAME=	sfwbar
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0_beta15
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	tino.engel@mail.de
COMMENT=	Flexible taskbar application for wayland compositors
WWW=		https://github.com/LBCrion/sfwbar

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR} \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell \
		libjson-c.so:devel/json-c \
		libwayland-client.so:graphics/wayland

USES=		gnome meson pkgconfig python:run

USE_GITHUB=	yes
GH_ACCOUNT=	LBCrion

USE_GNOME=	cairo gdkpixbuf2 gtk30

MESON_ARGS=	-Dbluez=enabled \
		-Dbsdctl=enabled \
		-Didleinhibit=enabled \
		-Diwd=enabled \
		-Dnetwork=enabled

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		ALSA MPD NM PULSEAUDIO XKB
OPTIONS_DEFAULT=	ALSA MPD NM PULSEAUDIO XKB
OPTIONS_SUB=		yes

ALSA_DESC=		ALSA audio volume control
MPD_DESC=		Music player daemon control
NM_DESC=		Network manager module
PULSEAUDIO_DESC=	Pulse audio volume control
XKB_DESC=		XkbCommon keyboard layout conversion support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MESON_ENABLED=	alsa

MPD_LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient
MPD_MESON_ENABLED=	mpd

NM_MESON_ENABLED=	nm

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	pulse

XKB_LIB_DEPENDS=	libxkbregistry.so:x11/libxkbcommon
XKB_MESON_ENABLED=	xkb

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MALSA} || ${PORT_OPTIONS:MPULSEAUDIO}
PLIST_SUB+=	VOLUME=""
.else
PLIST_SUB+=	VOLUME="@comment "
.endif

.include <bsd.port.post.mk>
