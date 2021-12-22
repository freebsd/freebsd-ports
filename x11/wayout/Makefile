PORTNAME=	wayout
DISTVERSION=	0.1.2
CATEGORIES=	x11
MASTER_SITES=	https://git.sr.ht/~proycon/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Output simple text to a Wayland desktop widget

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo pango
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	EPOLL MANPAGES
OPTIONS_DEFAULT=EPOLL MANPAGES

EPOLL_DESC=		Handle signals via epoll-shim
EPOLL_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim
EPOLL_MESON_ENABLED=	handle-signals

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
