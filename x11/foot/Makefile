# $FreeBSD$

PORTNAME=	foot
DISTVERSION=	1.6.2
CATEGORIES=	x11
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://github.com/jbeich/${PORTNAME}/commit/
PATCHFILES+=	301fd904df8f.patch:-p1 # main: correct header for mode macros
PATCHFILES+=	8fc036b2b31c.patch:-p1 # client/server: switch to POSIX header for sockaddr_un
PATCHFILES+=	7d60eb475c3f.patch:-p1 # terminal: add/exclude missing headers
PATCHFILES+=	0541c4377d34.patch:-p1 # uri: switch to conservative maximum hostname lengthb
PATCHFILES+=	225a19d49aa8.patch:-p1 # slave: skip e310487dae99 if not supported
PATCHFILES+=	859e9b145be2.patch:-p1 # client: adjust overflow check on 32-bit (i386, armv7)
PATCHFILES+=	0fa2bf34d323.patch:-p1 # shm: silence -Wunused-function on i386
PATCHFILES+=	5937c4157c6d.patch:-p1 # shm: disable fallocate optimization if not supported
PATCHFILES+=	6614d6a60753.patch:-p1 # shm: unbreak build without memfd_create
PATCHFILES+=	400e06127154.patch:-p1 # render: set thread name in a portable way
PATCHFILES+=	237a8fdcf8bb.patch:-p1 # meson: don't force POSIX compliance
PATCHFILES+=	754b0b8900be.patch:-p1 # meson: libpthread may lack C11 threads e.g., on FreeBSD
PATCHFILES+=	30243d39e602.patch:-p1 # meson: require epoll-shim on BSDs
PATCHFILES+=	db419ae55d46.patch:-p1 # meson: optionalize terminfo dependency

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Fast, lightweight and minimalistic Wayland terminal emulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		tllist>=1.0.4:devel/tllist \
		wayland-protocols>0:graphics/wayland-protocols \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libfcft.so:x11-fonts/fcft \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig xorg
USE_XORG=	pixman
WRKSRC=		${WRKDIR}/${PORTNAME}
MESON_ARGS=	-Dterminfo=false

# XXX Drop after FreeBSD 12.1 EOL
.if exists(/usr/lib/clang/8.0.1)
# prompt.c:45:21: error: suggest braces around initialization of subobject [-Werror,-Wmissing-braces]
CFLAGS+=	-Wno-error=missing-braces
.endif

.include <bsd.port.mk>
