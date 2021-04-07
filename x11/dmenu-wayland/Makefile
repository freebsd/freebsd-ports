PORTNAME=	dmenu-wayland
PORTVERSION=	0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

PATCH_SITES=	https://github.com/nyyManni/dmenu-wayland/commit/
PATCHFILES=	b646f4d14c627d9a4300d9d015fb8e9b5cb2abef.patch:-p1

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Efficient dynamic menu for wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gnome meson pkgconfig

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/wayland-protocols.pc:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USE_GITHUB=	yes
GH_ACCOUNT=	nyyManni

USE_GNOME=	cairo glib20 pango

PLIST_FILES=	bin/dmenu-wl \
		bin/dmenu-wl_path \
		bin/dmenu-wl_run \
		man/man1/dmenu-wl.1.gz

.include <bsd.port.mk>
