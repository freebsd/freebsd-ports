PORTNAME=	sway
DISTVERSION?=	1.8.1-216 # git rev-list --count 1.8.1..
DISTVERSIONSUFFIX?=	-g9d666a08e
PORTREVISION=	1
CATEGORIES=	x11-wm wayland
PKGNAMESUFFIX?=	-devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	cd9d1038a822.patch:-p1 # https://github.com/swaywm/sway/pull/5090
PATCHFILES+=	1f1c83e83a1a.patch:-p1 # https://github.com/swaywm/sway/pull/5090

MAINTAINER=	jbeich@FreeBSD.org
COMMENT?=	i3-compatible Wayland compositor (development snapshot)
WWW?=		https://swaywm.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.24:graphics/wayland-protocols \
		wlroots>=0.17.0<0.18.0:x11-toolkits/wlroots
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libevdev.so:devel/libevdev \
		libudev.so:devel/libudev-devd \
		libpcre2-8.so:devel/pcre2 \
		libwayland-egl.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig xorg
USE_GITHUB=	yes
USE_GNOME=	cairo pango
USE_XORG=	pixman
GH_ACCOUNT?=	swaywm
MESON_ARGS=	-Dsd-bus-provider=basu

CONFLICTS_INSTALL?=	${PORTNAME} ${PORTNAME}fx

OPTIONS_DEFINE=	BASU MANPAGES PIXBUF SWAYBG X11
OPTIONS_DEFAULT=BASU MANPAGES PIXBUF SWAYBG X11
OPTIONS_SUB=	yes

BASU_DESC=		Tray in swaybar via basu
BASU_LIB_DEPENDS=	libbasu.so:devel/basu
BASU_MESON_ENABLED=	tray

MANPAGES_BUILD_DEPENDS=	scdoc>=1.9.2:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages

PIXBUF_USE=		GNOME=gdkpixbuf2
PIXBUF_MESON_ENABLED=	gdk-pixbuf

SWAYBG_DESC=		Default command to set background
SWAYBG_RUN_DEPENDS=	swaybg:x11/swaybg

X11_USE=		XORG=xcb
X11_LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm
X11_MESON_ENABLED=	xwayland

post-patch:
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e '/config\.in/{ N; s/@BASENAME@/&.sample/; }' \
		${WRKSRC}/meson.build
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
