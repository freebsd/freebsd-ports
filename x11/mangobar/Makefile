PORTNAME=	mangobar
DISTVERSION=	0.2.2
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Simple bar for x11-wm/mango
WWW=		https://github.com/mangowm/mangobar

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>=5.8:devel/evdev-proto \
		tllist>=1.1.0:devel/tllist \
		wayland-protocols>=1.24:graphics/wayland-protocols \
		wayland-scanner:graphics/wayland
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libbasu.so:devel/basu \
		libcjson.so:devel/libcjson \
		libfcft.so:x11-fonts/fcft \
		libpixman-1.so:x11/pixman \
		libpulse.so:audio/pulseaudio \
		libudev.so:devel/libudev-devd \
		libwayland-server.so:graphics/wayland

USES=		gnome meson ninja pkgconfig python:build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	mangowm
USE_GNOME=	cairo gdkpixbuf pango

SHEBANG_FILES=	scripts/gen_defaults.py

SUB_FILES=	pkg-message

PLIST_FILES=	bin/mangobar \
		share/mangobar/config.jsonc \
		share/mangobar/style.css

post-patch:
	${REINPLACE_CMD} \
		-e 's,%%PYTHON_VERSION%%,${PYTHON_VERSION},1' \
		${WRKSRC}/meson.build

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config.jsonc ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/style.css ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
