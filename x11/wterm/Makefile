# New ports collection makefile for:   wterm
# Version required: 	6.2.6
# Date created:		25 February 1999
# Whom:		 	Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=	wterm-6.2.6
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.dct.com/pub/WindowMaker/WTerm/ \
		http://wm.current.nu/files/ \
		ftp://pong.csh.rit.edu/pub/mirrors/wterm/

MAINTAINER=	cpiazza@home.net

BUILD_DEPENDS=	${PREFIX}/lib/libWINGs.a:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-transparency --enable-xpm-background \
		--disable-delete-key --disable-backspace-key \
		--enable-next-scrollbar

MAN1=		wterm.1

.include <bsd.port.mk>
