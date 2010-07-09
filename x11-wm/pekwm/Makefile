# Ports collection makefile for:	pekwm
# Date created:			Nov 1, 2002
# Whom:				anders@hack.org
#
# $FreeBSD$
#

PORTNAME=	pekwm
PORTVERSION=	0.1.12
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://pekwm.org/projects/3/files/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Light, Unobtrusive, and configurable windowmanager

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

USE_XORG=	xft xpm x11
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shape --enable-xinerama --enable-xrandr \
		--enable-xft --enable-image-xpm --enable-image-jpeg \
		--enable-image-png --disable-debug \
		--disable-pedantic --enable-menus --enable-harbour
CFLAGS+=	-DICONV_CONST -I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -liconv"
MAN1=		pekwm.1
MANCOMPRESSED=	no

# replace calls to obsolete libpng12 functions
post-extract:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|; \
			s|png_check_sig(sig, PImageLoaderPng::PNG_SIG_BYTES) !=|png_sig_cmp(sig, 0, PImageLoaderPng::PNG_SIG_BYTES) ==|' \
		${WRKSRC}/src/PImageLoaderPng.cc

post-patch:
	${REINPLACE_CMD} -e 's|libpng12|libpng14|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
