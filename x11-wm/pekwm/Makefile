# Created by: anders@hack.org
# $FreeBSD$

PORTNAME=	pekwm
PORTVERSION=	0.1.16
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://pekwm.org/projects/3/files/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Light, Unobtrusive, and configurable windowmanager

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

USE_XORG=	xft xpm x11
USE_GMAKE=	yes
USE_ICONV=	yes
USE_BZIP2=	yes
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shape --enable-xinerama --enable-xrandr \
		--enable-xft --enable-image-xpm --enable-image-jpeg \
		--enable-image-png --disable-debug \
		--disable-pedantic
CFLAGS+=	-DICONV_CONST -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
MAN1=		pekwm.1
MANCOMPRESSED=	no

.include <bsd.port.mk>
