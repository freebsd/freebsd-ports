PORTNAME=	sway-audio-idle-inhibit
PORTVERSION=	s20211224
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
GH_TAGNAME=	4a68078
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
