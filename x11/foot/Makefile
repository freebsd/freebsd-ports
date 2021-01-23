# $FreeBSD$

PORTNAME=	foot
DISTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://codeberg.org/dnkl/${PORTNAME}/commit/
PATCHFILES+=	fd4511a3dc9f.patch:-p1 # main: correct header for mode macros
PATCHFILES+=	dd485d941499.patch:-p1 # client/server: switch to POSIX header for sockaddr_un
PATCHFILES+=	14e761179b8c.patch:-p1 # terminal: add/exclude missing headers
PATCHFILES+=	fb660262ab92.patch:-p1 # uri: switch to conservative maximum hostname length
PATCHFILES+=	e462419e348a.patch:-p1 # slave: skip e310487dae99 if not supported
PATCHFILES+=	6626ef5807a6.patch:-p1 # shm: silence -Wunused-function on i386
PATCHFILES+=	93fd77e01b25.patch:-p1 # shm: disable fallocate optimization if not supported
PATCHFILES+=	fcf3f124d626.patch:-p1 # shm: unbreak build without memfd_create
PATCHFILES+=	9b09049c1ccf.patch:-p1 # render: set thread name in a portable way
PATCHFILES+=	909938b83c7f.patch:-p1 # meson: don't force POSIX compliance
PATCHFILES+=	796301f2281f.patch:-p1 # meson: libpthread may lack C11 threads e.g., on FreeBSD
PATCHFILES+=	3ac107ce821f.patch:-p1 # meson: require epoll-shim on BSDs
PATCHFILES+=	0b07bf78f055.patch:-p1 # meson: depend on wayland-client when using wayland-protocols
PATCHFILES+=	8b092256d1ce.patch:-p1 # meson: optionalize terminfo dependency
PATCHFILES+=	ab040d0d6f5c.patch:-p1 # completions/zsh: unbreak with BSD find(1)
PATCHFILES+=	c70694bd8f40.patch:-p1 # client: explicitly use a 64-bit type for ‘total_len’
PATCHFILES+=	1f745655ac98.patch:-p1 # shm: don’t check for __i386__ and __x86_64__ - there are other architectures out there

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
