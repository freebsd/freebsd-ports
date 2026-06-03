PORTNAME=	river-classic
DISTVERSION=	0.3.15
CATEGORIES=	x11-wm wayland
MASTER_SITES=	https://codeberg.org/river/river-classic/releases/download/v${DISTVERSIONFULL}/
DISTFILES=	river-classic-${DISTVERSIONFULL}${EXTRACT_SUFX}

MAINTAINER=	siva@FreeBSD.org
COMMENT=	Dynamic tiling Wayland compositor
WWW=		https://isaacfreund.com/software/river/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwayland-server.so:graphics/wayland \
		libwlroots-0.20.so:x11-toolkits/wlroots020 \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		pkgconfig xorg zig:015
USE_XORG=	pixman

OPTIONS_DEFINE=	MANPAGES X11
OPTIONS_DEFAULT=MANPAGES X11
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_CONFIGURE_ON=	-Dman-pages=true
MANPAGES_CONFIGURE_OFF=	-Dman-pages=false

X11_CONFIGURE_ON=	-Dxwayland=true
X11_CONFIGURE_OFF=	-Dxwayland=false

ZIG_ARGS+=	-Dstrip

do-test:
	@(cd ${WRKSRC} && ${TEST_ENV} zig build test ${CONFIGURE_ARGS})

.include <bsd.port.mk>
