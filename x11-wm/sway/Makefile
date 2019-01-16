# $FreeBSD$

PORTNAME=	sway
DISTVERSION=	1.0-beta.2-204
DISTVERSIONSUFFIX=	-g70637b40
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	i3-compatible Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols \
		wlroots>=0.2.65:x11-toolkits/wlroots
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libevdev.so:devel/libevdev \
		libpcre.so:devel/pcre \
		libwayland-egl.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 pango
USE_XORG=	pixman
GH_ACCOUNT=	swaywm
MESON_ARGS=	-Dsway-version="${DISTVERSIONFULL}"

OPTIONS_DEFINE=	MANPAGES SUID X11
OPTIONS_DEFAULT=MANPAGES SUID X11
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc

SUID_DESC=		setuid bit on "sway" binary (required for DRM session)
SUID_PLIST_SUB=		MAYBE_SUID="@(,,4755) "
SUID_PLIST_SUB_OFF=	MAYBE_SUID=""

X11_USE=		XORG=xcb
X11_MESON_TRUE=		enable-xwayland

post-patch:
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e '/config\.in/{ N; s/@BASENAME@/&.sample/; }' \
		${WRKSRC}/meson.build
# Let terminal chooser pick default
	@${REINPLACE_CMD} -e 's/urxvt/swayterm/' \
		${WRKSRC}/config.in

post-patch-MANPAGES-off:
	@${REINPLACE_CMD} -i '' "s/'scdoc/&-disabled/" ${WRKSRC}/meson.build

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/swayterm ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${ETCDIR}/config.d
# x11/libxkbcommon has --with-default-rules="xorg" but x11/libinput expects "evdev"
	${ECHO_CMD} 'input * xkb_rules evdev' >${STAGEDIR}${ETCDIR}/config.d/evdev

.include <bsd.port.mk>
