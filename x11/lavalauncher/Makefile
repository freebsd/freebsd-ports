PORTNAME=	lavalauncher
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~leon_plickat/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple launcher panel for Wayland desktops

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	EPOLL INOTIFY LIBRSVG2 MANPAGES
OPTIONS_DEFAULT=EPOLL INOTIFY LIBRSVG2 MANPAGES
OPTIONS_EXCLUDE=${LIBRSVG2_DEFAULT:Mlegacy:C/.+/LIBRSVG2/}

EPOLL_DESC=		Handle signals via epoll-shim
EPOLL_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim
EPOLL_MESON_ENABLED=	handle-signals

INOTIFY_DESC=		Watch configuration file via libinotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_MESON_ENABLED=	watch-config

LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_MESON_ENABLED=	librsvg

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build
# Respect PREFIX when looking for system .conf files
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},' \
		${WRKSRC}/doc/lavalauncher.1.scd \
		${WRKSRC}/src/lavalauncher.c

.include <bsd.port.mk>
