# $FreeBSD$

PORTNAME=	grim
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	6994df611f55.patch:-p1

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
MESON_ARGS=	-Dwerror=false # https://github.com/emersion/grim/issues/37
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	JPEG MANPAGES
OPTIONS_DEFAULT=JPEG MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ON=	-Dman-pages=enabled
MANPAGES_MESON_OFF=	-Dman-pages=disabled
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

JPEG_USES=	jpeg
JPEG_MESON_ON=	-Djpeg=enabled
JPEG_MESON_OFF=	-Djpeg=disabled

.include <bsd.port.mk>
