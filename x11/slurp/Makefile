PORTNAME=	slurp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Select a region in a Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo
GH_ACCOUNT=	emersion
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
