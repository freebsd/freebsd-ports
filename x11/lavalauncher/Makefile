# $FreeBSD$

PORTNAME=	lavalauncher
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://git.sr.ht/~leon_plickat/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://git.sr.ht/~leon_plickat/${PORTNAME}/commit/
PATCHFILES+=	542e8c948889.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple launcher panel for Wayland desktops

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	EPOLL INOTIFY LIBRSVG2 MANPAGES
OPTIONS_DEFAULT=EPOLL INOTIFY MANPAGES

EPOLL_DESC=		Handle signals via epoll-shim
EPOLL_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim
EPOLL_MESON_ENABLED=	handle-signals

INOTIFY_DESC=		Watch configuration file via libinotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_MESON_ENABLED=	watch-config

LIBRSVG2_USE=		GNOME=glib20
LIBRSVG2_LIB_DEPENDS=	librsvg-2.so.2:graphics/librsvg2-rust
LIBRSVG2_MESON_ENABLED=	librsvg

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

post-patch:
# Respect PREFIX when looking for system .conf files
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/lavalauncher.c

.include <bsd.port.mk>
