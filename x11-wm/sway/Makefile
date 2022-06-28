PORTNAME=	sway
DISTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	x11-wm wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	cd9d1038a822.patch:-p1 # https://github.com/swaywm/sway/pull/5090
PATCHFILES+=	f98ca3ab7ca1.patch:-p1 # https://github.com/swaywm/sway/pull/5090
PATCHFILES+=	17ee30d07058.patch:-p1 # wlroots 0.16
PATCHFILES+=	d6f8820a8b71.patch:-p1 # wlroots 0.16
PATCHFILES+=	8ca2847b4253.patch:-p1 # wlroots 0.16
PATCHFILES+=	ee7668c1f2b5.patch:-p1 # wlroots 0.16
PATCHFILES+=	30d27b5996f3.patch:-p1 # wlroots 0.16
PATCHFILES+=	f795aa1c95b1.patch:-p1 # wlroots 0.16
PATCHFILES+=	9a6687ee04db.patch:-p1 # wlroots 0.16
PATCHFILES+=	f8990523b456.patch:-p1 # wlroots 0.16
PATCHFILES+=	85d1c98476b6.patch:-p1 # wlroots 0.16
PATCHFILES+=	04676936e71f.patch:-p1 # wlroots 0.16
PATCHFILES+=	0345148ea667.patch:-p1 # wlroots 0.16
PATCHFILES+=	49b3ac9a2ce1.patch:-p1 # wlroots 0.16
PATCHFILES+=	440d0bc22d57.patch:-p1 # wlroots 0.16
PATCHFILES+=	6c4c0387a24b.patch:-p1 # wlroots 0.16
PATCHFILES+=	acdb48a59c26.patch:-p1 # wlroots 0.16
PATCHFILES+=	3f600565e4dd.patch:-p1 # wlroots 0.16
PATCHFILES+=	26a0e97634dc.patch:-p1 # wlroots 0.16
PATCHFILES+=	1c69d0e72fe8.patch:-p1 # wlroots 0.16
PATCHFILES+=	94dbc6a92a03.patch:-p1 # wlroots 0.16
PATCHFILES+=	6b97c4fa7109.patch:-p1 # wlroots 0.16
PATCHFILES+=	aaa6c4ac892d.patch:-p1 # wlroots 0.16
PATCHFILES+=	07bfeb2abcb4.patch:-p1 # wlroots 0.16

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	i3-compatible Wayland compositor
WWW=		https://swaywm.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.24:graphics/wayland-protocols \
		wlroots>=0.16.0<0.17.0:x11-toolkits/wlroots
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libevdev.so:devel/libevdev \
		libudev.so:devel/libudev-devd \
		libpcre.so:devel/pcre \
		libwayland-egl.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	swaybg:x11/swaybg

CONFLICTS_INSTALL=	${PORTNAME}-devel

USES=		compiler:c11 gl gnome meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		glesv2
USE_GNOME=	cairo pango
USE_XORG=	pixman
GH_ACCOUNT=	swaywm
MESON_ARGS=	-Dsd-bus-provider=basu

OPTIONS_DEFINE=	BASU MANPAGES PIXBUF X11
OPTIONS_DEFAULT=BASU MANPAGES PIXBUF X11
OPTIONS_SUB=	yes

BASU_DESC=		Tray in swaybar via basu
BASU_LIB_DEPENDS=	libbasu.so:devel/basu
BASU_MESON_ENABLED=	tray

MANPAGES_BUILD_DEPENDS=	scdoc>=1.9.2:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages

PIXBUF_USE=		GNOME=gdkpixbuf2
PIXBUF_MESON_ENABLED=	gdk-pixbuf

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
