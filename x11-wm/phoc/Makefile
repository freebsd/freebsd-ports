PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Phone compositor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wlroots>=0.12.0<0.13.0:x11-toolkits/wlroots
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/share/glib-2.0/schemas/org.gnome.mutter.gschema.xml:x11-wm/mutter

USES=		compiler:c11 gl gnome meson pkgconfig python:build shebangfix xorg
USE_GITLAB=	yes
USE_GL=		glesv2
USE_GNOME=	gnomedesktop3
USE_XORG=	pixman xcb
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/Phosh
GL_COMMIT=	527689df1300277af2cdfc872474c8322e38f690
SHEBANG_FILES=	build-aux/post_install.py
CFLAGS+=	-Wno-error=format-nonliteral # clang
PLIST_FILES=	bin/${PORTNAME}
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

# https://gitlab.gnome.org/World/Phosh/phoc/-/merge_requests/241
BUILD_DEPENDS:=	${BUILD_DEPENDS:N*wlroots*}
LIB_DEPENDS:=	${LIB_DEPENDS:N*wlroots*} \
		libudev.so:devel/libudev-devd \
		libdrm.so:graphics/libdrm \
		libseat.so:sysutils/seatd \
		libxcb-errors.so:x11/xcb-util-errors \
		libxcb-icccm.so:x11/xcb-util-wm
RUN_DEPENDS+=	xwayland-devel>0:x11-servers/xwayland-devel
USE_XORG+=	x11
USE_GL+=	gbm egl
GL_TUPLE+=	https://source.puri.sm:Librem5:wlroots:b2fd6d8dd88d67ee48be67f5be4ee614a5826b13:wlroots/subprojects/wlroots
PLIST_FILES+=	"@comment libdata/pkgconfig/wlroots.pc"

.include <bsd.port.mk>
