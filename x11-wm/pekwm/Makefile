# Ports collection makefile for:	pekwm
# Date created:			Nov 1, 2002
# Whom:				anders@hack.org
#
# $FreeBSD$
#

PORTNAME=	pekwm
PORTVERSION=	0.1.11
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://pekwm.org/projects/3/files/ \
		http://www.carpetsmoker.net/distfiles/ \
		http://www.xs4all.nl/~tournoij/distfiles/ \
		http://www.rwxrwxrwx.net/distfiles/

MAINTAINER=	carpetsmoker@rwxrwxrwx.net
COMMENT=	Light, Unobtrusive, and configurable windowmanager

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
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

.include <bsd.port.mk>
