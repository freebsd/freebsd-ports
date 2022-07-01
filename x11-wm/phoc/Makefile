PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Phone compositor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.15:graphics/wayland-protocols \
		wlroots>=0.14.1<0.15.0:x11-toolkits/wlroots
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
GL_COMMIT=	b686cc5010a8d0f9a654a8171e90415e0717e10c
SHEBANG_FILES=	build-aux/post_install.py
CFLAGS+=	-Wno-error=format-nonliteral # clang
PLIST_FILES=	bin/${PORTNAME}
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

.include "${.CURDIR}/Makefile.wlroots"
.include <bsd.port.mk>
