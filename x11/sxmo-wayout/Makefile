PORTNAME=	wayout
DISTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~proycon/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
PKGNAMEPREFIX=	sxmo-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Output simple text to a Wayland desktop widget
WWW=		https://git.sr.ht/~proycon/wayout

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo pango
CFLAGS+=	-Wno-error=strict-prototypes # Clang 15, similar to wlclock
PLIST_FILES=	bin/${PKGBASE}

OPTIONS_DEFINE=	EPOLL MANPAGES
OPTIONS_DEFAULT=EPOLL MANPAGES

EPOLL_DESC=		Handle signals via epoll-shim
EPOLL_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim
EPOLL_MESON_ENABLED=	handle-signals

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

post-install:
# Rename to avoid conflict with x11/wayout
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PKGBASE}

.include <bsd.port.mk>
