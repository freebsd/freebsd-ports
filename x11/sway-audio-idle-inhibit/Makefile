PORTNAME=	sway-audio-idle-inhibit
DISTVERSIONPREFIX=	v
PORTVERSION=	0.1.1
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Disable swayidle during audio playback/recording

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libwayland-client.so:graphics/wayland

USES=		compiler:c++11-lang meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ErikReider
GH_PROJECT=	SwayAudioIdleInhibit
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
