# $FreeBSD$

PORTNAME=	libwraster
PORTVERSION=	0.95.5
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
		libtiff.so:${PORTSDIR}/graphics/tiff

USES=		pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_XORG=	xft xinerama xmu xpm
BUILD_WRKSRC=	${WRKSRC}/wrlib
INSTALL_WRKSRC=	${WRKSRC}/wrlib
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-gnustepdir="${PREFIX}/GNUstep" \
		--enable-modelock \
		--enable-xinerama --enable-usermenu \
		--with-x
CPPFLAGS+=	-DPREFIX=\\\"${PREFIX}\\\" -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		get-wraster-flags.1

pre-build:
	cd ${WRKSRC} && ${MAKE} config-paths.h

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} \
	    get-wraster-flags.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
