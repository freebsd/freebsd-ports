# $FreeBSD$

PORTNAME=	fnott
DISTVERSION=	1.0.1
CATEGORIES=	x11
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Keyboard-driven notification daemon for wlroots-based compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		tllist>=1.0.1:devel/tllist \
		wayland-protocols>0:graphics/wayland-protocols \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libepoll-shim.so:devel/libepoll-shim \
		libpng.so:graphics/png \
		libwayland-client.so:graphics/wayland \
		libfcft.so:x11-fonts/fcft

USES=		compiler:c11 meson pkgconfig xorg
USE_XORG=	pixman
WRKSRC=		${WRKDIR}/${PORTNAME}

# XXX Drop after FreeBSD 12.1 EOL
.if exists(/usr/lib/clang/8.0.1)
# notification.c:545:13: error: suggest braces around initialization of subobject [-Werror,-Wmissing-braces]
CFLAGS+=	-Wno-error=missing-braces
.endif

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/xdg.c

.include <bsd.port.mk>
