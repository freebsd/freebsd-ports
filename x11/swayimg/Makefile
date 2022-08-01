PORTNAME=	swayimg
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	2a07af9d2362.patch:-p1 # https://github.com/artemsen/swayimg/issues/37
PATCHFILES+=	2e885eadec15.patch:-p1 # https://github.com/artemsen/swayimg/pull/36

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Image viewer for Sway/Wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	artemsen
MESON_ARGS=	-Dversion="${DISTVERSIONFULL}"
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		man/man5/${PORTNAME}rc.5.gz \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/64x64/apps/${PORTNAME}.png \
		${NULL}

OPTIONS_DEFINE=	AVIF BASH GIF JPEG JXL LIBEXIF LIBRSVG2 PNG TIFF WEBP
OPTIONS_DEFAULT=AVIF BASH GIF JPEG JXL LIBEXIF LIBRSVG2 PNG TIFF WEBP
OPTIONS_EXCLUDE=${LIBRSVG2_DEFAULT:Mlegacy:C/.+/LIBRSVG2/}

AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_MESON_ENABLED=	avif

BASH_BUILD_DEPENDS=	bash-completion>0:shells/bash-completion
BASH_MESON_ENABLED=	bash
BASH_PLIST_FILES=	share/bash-completion/completions/${PORTNAME}

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_USES=		localbase:ldflags
GIF_MESON_ENABLED=	gif

JPEG_USES=		jpeg
JPEG_MESON_ENABLED=	jpeg

JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_MESON_ENABLED=	jxl

LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
LIBEXIF_MESON_ENABLED=	exif

LIBRSVG2_USES=		gnome
LIBRSVG2_USE=		GNOME=cairo,librsvg2
LIBRSVG2_MESON_ENABLED=	svg

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ENABLED=	png

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	tiff

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_MESON_ENABLED=	webp

.include <bsd.port.mk>
