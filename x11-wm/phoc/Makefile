PORTNAME=	phoc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.0
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Phone compositor
WWW=		https://gitlab.gnome.org/World/Phosh/phoc

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.15:graphics/wayland-protocols \
		wlroots>=0.15.1<0.16.0:x11-toolkits/wlroots
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/share/glib-2.0/schemas/org.gnome.mutter.gschema.xml:x11-wm/mutter

FLAVORS=	default phosh

USES=		compiler:c11 gl gnome meson pkgconfig python:build shebangfix xorg
USE_GITLAB=	yes
USE_GL=		glesv2
USE_GNOME=	gnomedesktop3
USE_XORG=	pixman xcb
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/Phosh
GL_COMMIT=	d14ed975c6e2f2410e918cb0529883d84a047c93
SHEBANG_FILES=	build-aux/post_install.py
CFLAGS+=	-Wno-error=format-nonliteral # clang
PLIST_FILES=	bin/${PORTNAME}
GLIB_SCHEMAS=	sm.puri.phoc.gschema.xml

.if ${FLAVOR:U} == phosh || make(makesum)
PKGNAMESUFFIX=	-${FLAVOR}
COMMENT+=	(with patched wlroots from PureOS)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-private-wlroots
CONFLICTS_INSTALL=	${PORTNAME}
.include "${.CURDIR}/Makefile.wlroots"
.else
COMMENT+=	(with system wlroots)
CONFLICTS_INSTALL=	${PORTNAME}-phosh
.include "${.CURDIR:H:H}/x11-toolkits/wlroots015/override.mk"
.endif

.include <bsd.port.mk>
