# $FreeBSD$

PORTNAME=	dmenu-wayland
PORTVERSION=	0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Efficient dynamic menu for wayland

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

USES=		gnome meson pkgconfig

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
