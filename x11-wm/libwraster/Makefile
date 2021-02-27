# $FreeBSD$

PORTNAME=	libwraster
PORTVERSION=	0.95.9
PORTREVISION=	1
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	http://windowmaker.org/pub/source/release/
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Window Maker raster graphics library

LICENSE=	LGPL21

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libjbig.so:graphics/jbigkit \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USES=		jpeg libtool localbase pathfix pkgconfig xorg
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xft xinerama xmu xpm
BUILD_WRKSRC=	${WRKSRC}/wrlib
INSTALL_WRKSRC=	${WRKSRC}/wrlib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-localedir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-gnustepdir="${PREFIX}/GNUstep" \
		--enable-modelock \
		--enable-xinerama \
		--enable-usermenu \
		--enable-wmreplace \
		--with-x
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	IMAGEMAGICK
OPTIONS_DEFAULT=	IMAGEMAGICK

IMAGEMAGICK_LIB_DEPENDS=	libMagickWand-${IMAGEMAGICK_DEFAULT}.so:graphics/ImageMagick${IMAGEMAGICK_DEFAULT}
IMAGEMAGICK_CONFIGURE_OFF=	--disable-magick

.include <bsd.port.options.mk>

post-patch-IMAGEMAGICK-on:
.if ${IMAGEMAGICK_DEFAULT} == 6
	@${REINPLACE_CMD} -e '/MagickWand\.h/s,MagickWand/,wand/,' \
		${WRKSRC}/configure ${WRKSRC}/wrlib/load_magick.c
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} config-paths.h

.include <bsd.port.mk>
