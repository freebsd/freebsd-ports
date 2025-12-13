PORTNAME=	mangowc
DISTVERSION=	0.10.7
CATEGORIES=	x11-wm

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Lightweight, high-performance Wayland compositor built on dwl
WWW=		https://mangowc.vercel.app

LICENSE=	CC0-1.0 GPLv3 MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSE.tinywl
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE.dwl
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.wlroots

BUILD_DEPENDS=	git:devel/git \
		hwdata>=0.399:misc/hwdata \
		wayland-protocols>=1.24:graphics/wayland-protocols
LIB_DEPENDS=	libdisplay-info.so:sysutils/libdisplay-info \
		libdrm.so:graphics/libdrm \
		libevdev.so:devel/libevdev \
		libinput.so:x11/libinput \
		libjson-c.so:devel/json-c \
		libliftoff.so:graphics/libliftoff \
		libpcre2-8.so:devel/pcre2 \
		libpixman-1.so:x11/pixman \
		libscenefx-0.4.so:x11-toolkits/scenefx04 \
		libseat.so:sysutils/seatd \
		libudev.so:devel/libudev-devd \
		libwayland-egl.so:graphics/wayland \
		libwlroots-0.19.so:x11-toolkits/wlroots019 \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb.so:x11/libxcb \
		libxkbcommon.so:x11/libxkbcommon

RUN_DEPENDS=	hwdata>=0.399:misc/hwdata \
		Xwayland:x11-servers/xwayland

USES=		meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	DreamMaoMao

SUB_FILES=	pkg-message

PLIST_FILES=	bin/mango \
		bin/mmsg \
		etc/mango/config.conf \
		share/wayland-sessions/mango.desktop

.include <bsd.port.mk>
