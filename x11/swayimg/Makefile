PORTNAME=	swayimg
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Image viewer for Sway/Wayland
WWW=		https://github.com/artemsen/swayimg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.35:graphics/wayland-protocols
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libwayland-client.so:graphics/wayland \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	artemsen
MESON_ARGS=	-Dversion="${DISTVERSIONFULL}"
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man5/${PORTNAME}rc.5.gz \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/64x64/apps/${PORTNAME}.png \
		share/icons/hicolor/128x128/apps/${PORTNAME}.png \
		share/icons/hicolor/256x256/apps/${PORTNAME}.png \
		${DATADIR}/${PORTNAME}rc \
		${NULL}

# XXX Drop after FreeBSD 13.4 EOL around 2026-01-31
# https://cgit.freebsd.org/src/commit/?id=af93fea71038
.if !exists(/usr/include/sys/timerfd.h)
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim
.endif

OPTIONS_DEFINE=	AVIF BASH GIF HEIF JPEG JSON JXL LIBEXIF LIBRSVG2 \
		OPENEXR PNG RAW SIXEL TIFF WEBP ZSH
OPTIONS_DEFAULT=AVIF BASH GIF HEIF JPEG JSON JXL LIBEXIF LIBRSVG2 \
		OPENEXR PNG RAW SIXEL TIFF WEBP ZSH
OPTIONS_EXCLUDE=${LIBRSVG2_DEFAULT:Mlegacy:C/.+/LIBRSVG2/}

AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_MESON_ENABLED=	avif

BASH_BUILD_DEPENDS=	bash-completion>0:shells/bash-completion
BASH_MESON_ENABLED=	bash
BASH_PLIST_FILES=	share/bash-completion/completions/${PORTNAME}

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_MESON_ENABLED=	gif

HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_MESON_ENABLED=	heif

JPEG_USES=		jpeg
JPEG_MESON_ENABLED=	jpeg

JSON_LIB_DEPENDS=	libjson-c.so:devel/json-c
JSON_MESON_ENABLED=	compositor

JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_MESON_ENABLED=	jxl

LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
LIBEXIF_MESON_ENABLED=	exif

LIBRSVG2_USES=		gnome
LIBRSVG2_USE=		GNOME=cairo,librsvg2
LIBRSVG2_MESON_ENABLED=	svg

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr
OPENEXR_MESON_ENABLED=	exr

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ENABLED=	png

RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_MESON_ENABLED=	raw

SIXEL_DESC=		Sixel graphics support
SIXEL_LIB_DEPENDS=	libsixel.so:graphics/libsixel
SIXEL_MESON_ENABLED=	sixel

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	tiff

WEBP_LIB_DEPENDS=	libwebpdemux.so:graphics/webp
WEBP_MESON_ENABLED=	webp

ZSH_MESON_ENABLED=	zsh
ZSH_PLIST_FILES=	share/zsh/site-functions/_${PORTNAME}

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/extra/${PORTNAME}rc \
		${WRKSRC}/extra/${PORTNAME}rc.5 \
		${WRKSRC}/src/config.c

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=enabled"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
