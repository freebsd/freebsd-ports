PORTNAME=	grim
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~emersion/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Grab images from a Wayland compositor
WWW=		https://sr.ht/~emersion/grim/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libpng.so:graphics/png \
		libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	pixman
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	JPEG MANPAGES
OPTIONS_DEFAULT=JPEG MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

JPEG_USES=	jpeg
JPEG_MESON_ENABLED=	jpeg

.include <bsd.port.mk>
