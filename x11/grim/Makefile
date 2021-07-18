PORTNAME=	grim
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Grab images from a Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo
GH_ACCOUNT=	emersion
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	JPEG MANPAGES
OPTIONS_DEFAULT=JPEG MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

JPEG_USES=	jpeg
JPEG_MESON_ENABLED=	jpeg

.include <bsd.port.mk>
