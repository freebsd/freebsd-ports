# New ports collection makefile for:   wterm
# Date created:		25 February 1999
# Whom:		 	Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wterm
PORTVERSION= 	6.2.6
CATEGORIES=	x11
MASTER_SITES= 	ftp://ftp.kddlabs.co.jp/.10/X11/acontrib/wterm/ \
		ftp://ftp.riken.go.jp/pub/X11/acontrib/wterm/

MAINTAINER=	cpiazza@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/libWINGs.a:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-transparency --enable-xpm-background \
		--disable-delete-key --disable-backspace-key \
		--enable-next-scrollbar --enable-utmp --enable-wtmp
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		wterm.1

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/wterm

.include <bsd.port.mk>
