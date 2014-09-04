# $FreeBSD$

PORTNAME=	libwraster
PORTVERSION=	0.95.6
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	http://windowmaker.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	source/release
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Window Maker raster graphics library

LICENSE=	LGPL21

LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib \
		libpng15.so:${PORTSDIR}/graphics/png \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libwebp.so:${PORTSDIR}/graphics/webp \
		libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_XORG=	xft xinerama xmu xpm
BUILD_WRKSRC=	${WRKSRC}/wrlib
INSTALL_WRKSRC=	${WRKSRC}/wrlib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-gnustepdir="${PREFIX}/GNUstep" \
		--enable-modelock \
		--enable-xinerama --enable-usermenu \
		--with-x
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} config-paths.h

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} \
	    get-wraster-flags.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
