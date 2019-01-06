# $FreeBSD$

PORTNAME=	sway
DISTVERSION=	1.0-beta.2
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	4a11d0e470bc.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	i3-compatible Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libjson-c.so:devel/json-c \
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

SUID_DESC=		Install with setuid bit set
SUID_PLIST_SUB=		MAYBE_SUID="@(,,4755) "
SUID_PLIST_SUB_OFF=	MAYBE_SUID=""

X11_USE=		XORG=xcb
X11_MESON_TRUE=		enable-xwayland

post-patch:
# Let @sample handle default files under etc/
	@${REINPLACE_CMD} -e '/config\.in/{ N; s/@BASENAME@/&.sample/; }' \
		${WRKSRC}/meson.build

post-patch-MANPAGES-off:
	@${REINPLACE_CMD} -i '' "s/'scdoc/&-disabled/" ${WRKSRC}/meson.build

.include <bsd.port.mk>
