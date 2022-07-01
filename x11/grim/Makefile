PORTNAME=	grim
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	x11 wayland
MASTER_SITES=	https://git.sr.ht/~emersion/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://git.sr.ht/~emersion/${PORTNAME}/commit/
PATCHFILES+=	89e02e663fab.patch:-p1 # https://github.com/emersion/grim/pull/121

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Grab images from a Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	JPEG MANPAGES
OPTIONS_DEFAULT=JPEG MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

JPEG_USES=	jpeg
JPEG_MESON_ENABLED=	jpeg

.include <bsd.port.mk>
