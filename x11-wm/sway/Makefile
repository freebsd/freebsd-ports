# $FreeBSD$

PORTNAME=	sway
DISTVERSION=	1.0-beta.2-287
DISTVERSIONSUFFIX=	-g606f6a37
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	i3-compatible Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols \
		wlroots>=0.2.178:x11-toolkits/wlroots
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libevdev.so:devel/libevdev \
		libpcre.so:devel/pcre \
		libwayland-egl.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo pango
USE_XORG=	pixman
GH_ACCOUNT=	swaywm
MESON_ARGS=	-Dsway-version="${DISTVERSIONFULL}"

OPTIONS_DEFINE=	MANPAGES PIXBUF SUID X11
OPTIONS_DEFAULT=MANPAGES PIXBUF SUID X11
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	scdoc>=1.8.0:textproc/scdoc
MANPAGES_MESON_ON=	-Dman-pages=enabled
MANPAGES_MESON_OFF=	-Dman-pages=disabled

PIXBUF_USE=		GNOME=gdkpixbuf2
PIXBUF_MESON_ON=	-Dgdk-pixbuf=enabled
PIXBUF_MESON_OFF=	-Dgdk-pixbuf=disabled

SUID_DESC=		setuid bit on "sway" binary (required for DRM session)
SUID_PLIST_SUB=		MAYBE_SUID="@(,,4755) "
SUID_PLIST_SUB_OFF=	MAYBE_SUID=""

X11_USE=		XORG=xcb
X11_MESON_ON=		-Dxwayland=enabled
X11_MESON_OFF=		-Dxwayland=disabled

post-patch:
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e '/config\.in/{ N; s/@BASENAME@/&.sample/; }' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
