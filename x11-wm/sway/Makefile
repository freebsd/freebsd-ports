PORTNAME=	sway
DISTVERSION=	1.11
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	i3-compatible Wayland compositor
WWW=		https://swaywm.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.24:graphics/wayland-protocols
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libevdev.so:devel/libevdev \
		libudev.so:devel/libudev-devd \
		libpcre2-8.so:devel/pcre2 \
		libdrm.so:graphics/libdrm \
		libwayland-egl.so:graphics/wayland \
		libwlroots-0.19.so:x11-toolkits/wlroots019 \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig xorg
USE_GITHUB=	yes
USE_GNOME=	cairo pango
USE_XORG=	pixman
GH_ACCOUNT=	swaywm
MESON_ARGS=	-Dsd-bus-provider=basu

CONFLICTS_INSTALL=	${PORTNAME}-devel ${PORTNAME}fx

OPTIONS_DEFINE=	BASU MANPAGES PIXBUF SWAYBG X11
OPTIONS_DEFAULT=BASU MANPAGES PIXBUF SWAYBG X11
OPTIONS_SUB=	yes

BASU_DESC=		Tray in swaybar via basu
BASU_LIB_DEPENDS=	libbasu.so:devel/basu
BASU_MESON_ENABLED=	tray

MANPAGES_BUILD_DEPENDS=	scdoc>=1.9.2:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages

PIXBUF_USE=		GNOME=gdkpixbuf
PIXBUF_MESON_ENABLED=	gdk-pixbuf

SWAYBG_DESC=		Default command to set background
SWAYBG_RUN_DEPENDS=	swaybg:x11/swaybg

X11_USE=		XORG=xcb
X11_LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm

.include <bsd.port.options.mk>

# https://github.com/freebsd/freebsd-src/pull/1675
.if ${OPSYS} == FreeBSD && (${OSVERSION} < 1305503 \
 || ${OSVERSION} >= 1400000 && ${OSVERSION} < 1403505 \
 || ${OSVERSION} >= 1500000 && ${OSVERSION} < 1500052)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-wordexp
.endif

post-patch:
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e '/config\.in/{ N; s/@BASENAME@/&.sample/; }' \
		${WRKSRC}/meson.build
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build
.if exists(${.CURDIR}/files/extra-patch-wordexp)
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=275328
	@${REINPLACE_CMD} -e 's/_POSIX_C_SOURCE=200809L/_XOPEN_SOURCE=700/' \
		${WRKSRC}/meson.build
.endif

.include <bsd.port.mk>
