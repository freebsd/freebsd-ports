PORTNAME=	wmenu
DISTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~adnano/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	o.hushchenkov@gmail.com
COMMENT=	Efficient dynamic menu for Wayland
WWW=		https://sr.ht/~adnano/wmenu/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo pango

CPPFLAGS+=	`pkg-config --cflags epoll-shim`
LDFLAGS+=	`pkg-config --libs epoll-shim`

PLIST_FILES=	bin/wmenu \
		man/man1/wmenu.1.gz

.include <bsd.port.mk>
