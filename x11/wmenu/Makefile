PORTNAME=	wmenu
DISTVERSION=	0.1.7
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~adnano/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	o.hushchenkov@gmail.com
COMMENT=	Efficient dynamic menu for Wayland
WWW=		https://sr.ht/~adnano/wmenu/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo pango

# XXX Drop after FreeBSD 13.4 EOL around 2026-01-31
# https://cgit.freebsd.org/src/commit/?id=af93fea71038
.if !exists(/usr/include/sys/timerfd.h)
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim
CPPFLAGS+=	`pkg-config --cflags epoll-shim`
LDFLAGS+=	`pkg-config --libs epoll-shim`
.endif

PLIST_FILES=	bin/wmenu \
		share/man/man1/wmenu.1.gz

.include <bsd.port.mk>
