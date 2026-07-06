PORTNAME=	swayimg
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Image viewer for Sway/Wayland
WWW=		https://github.com/artemsen/swayimg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon
TEST_DEPENDS=	googletest>0:devel/googletest \
		dejavu>0:x11-fonts/dejavu

USES=		desktop-file-utils luajit meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	artemsen
MESON_ARGS=	-Dversion="${DISTVERSIONFULL}"
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/64x64/apps/${PORTNAME}.png \
		share/icons/hicolor/128x128/apps/${PORTNAME}.png \
		share/icons/hicolor/256x256/apps/${PORTNAME}.png \
		${DATADIR}/example.lua \
		${DATADIR}/${PORTNAME}.lua \
		${NULL}

# XXX Drop after FreeBSD 14.* EOL around 2028-11-30
# https://cgit.freebsd.org/src/commit/?id=3965de642c29
.if !exists(/usr/include/sys/inotify.h)
LIB_DEPENDS+=	libinotify.so:devel/libinotify
.endif

OPTIONS_DEFINE=	AVIF BASH EXIV2 GIF HEIF JPEG JXL LIBRSVG2 \
		OPENEXR OPENJPEG PNG RAW SIXEL TIFF WEBP ZSH
OPTIONS_DEFAULT=AVIF BASH DRM EXIV2 GIF HEIF JPEG JXL LIBRSVG2 \
		OPENEXR OPENJPEG PNG RAW SIXEL TIFF WAYLAND WEBP ZSH
OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	DRM WAYLAND
OPTIONS_EXCLUDE=${LIBRSVG2_DEFAULT:Mlegacy:C/.+/LIBRSVG2/}

AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_MESON_ENABLED=	avif

BASH_BUILD_DEPENDS=	bash-completion>0:shells/bash-completion
BASH_MESON_ENABLED=	bash
BASH_PLIST_FILES=	share/bash-completion/completions/${PORTNAME}

DRM_DESC=		KMS console support
DRM_LIB_DEPENDS=	libdrm.so:graphics/libdrm
DRM_MESON_ENABLED=	drm

EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_MESON_ENABLED=	exif

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_MESON_ENABLED=	gif

HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_MESON_ENABLED=	heif

JPEG_USES=		jpeg
JPEG_MESON_ENABLED=	jpeg

JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_MESON_ENABLED=	jxl

LIBRSVG2_USES=		gnome
LIBRSVG2_USE=		GNOME=cairo,librsvg2
LIBRSVG2_MESON_ENABLED=	svg

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
			libImath.so:math/Imath
OPENEXR_MESON_ENABLED=	exr

OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_MESON_ENABLED=	jp2

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ENABLED=	png

RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_MESON_ENABLED=	raw

SIXEL_DESC=		Sixel graphics support
SIXEL_LIB_DEPENDS=	libsixel.so:graphics/libsixel
SIXEL_MESON_ENABLED=	sixel

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	tiff

WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.35:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MESON_ENABLED=	wayland

WEBP_LIB_DEPENDS=	libwebpdemux.so:graphics/webp
WEBP_MESON_ENABLED=	webp

ZSH_MESON_ENABLED=	zsh
ZSH_PLIST_FILES=	share/zsh/site-functions/_${PORTNAME}

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/extra/${PORTNAME}.1 \
		${WRKSRC}/extra/lua2md.py \
		${WRKSRC}/src/luaengine.cpp

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=enabled"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
