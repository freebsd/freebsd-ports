# New ports collection makefile for:   wterm
# Version required: 	6.2.6
# Date created:		25 February 1999
# Whom:		 	Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.2 1999/04/14 04:49:46 mharo Exp $
#

DISTNAME=	wterm-6.2.6
CATEGORIES=	x11
MASTER_SITES=	ftp://beer.dct.com/pub/Applications/ \
		http://wm.current.nu/files/

MAINTAINER=	cpiazza@home.net

BUILD_DEPENDS=	${X11BASE}/lib/libWINGs.a:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-transparency --enable-xpm-background \
		--disable-delete-key --disable-backspace-key \
		--enable-next-scrollbar --enable-utmp --enable-wtmp
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		wterm.1

.include <bsd.port.mk>
