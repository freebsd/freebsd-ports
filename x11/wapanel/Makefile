PORTNAME=	wapanel
DISTVERSION=	1.1.0
PORTREVISION=	7
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop bar for Wayfire and other wlroots compositors
WWW=		https://firstbober.github.io/wapanel/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	https://github.com/Firstbober/wapanel/issues/39

BUILD_DEPENDS=	toml11>0:devel/toml11 \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf gtk30
GH_ACCOUNT=	Firstbober
MESON_ARGS=	-Dsystem_toml11=true

OPTIONS_DEFINE=	PULSEAUDIO
OPTIONS_DEFAULT=PULSEAUDIO
OPTIONS_SUB=	yes

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_TRUE=	volume-control

post-patch:
# Respect PREFIX for *.desktop
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/src/applets/task-switcher/task_switcher.cc \
		${WRKSRC}/thirdparty/xdgpp/xdg.hpp

.include <bsd.port.mk>
