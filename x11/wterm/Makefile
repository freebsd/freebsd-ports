# New ports collection makefile for:   wterm
# Date created:		25 February 1999
# Whom:		 	Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wterm
PORTVERSION=	6.2.9
CATEGORIES=	x11
MASTER_SITES= 	http://largo.windowmaker.org/files/

MAINTAINER=	adam-ports@blacktabby.org

BUILD_DEPENDS=	${X11BASE}/lib/libWINGs.a:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-transparency --enable-xpm-background \
		--disable-delete-key --disable-backspace-key \
		--enable-next-scrollbar --enable-utmp --enable-wtmp \
		--enable-menubar --enable-graphics
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include/WINGs"

MAN1=		wterm.1

post-extract:
	${RM} -f ${WRKSRC}/config.cache
	${RM} -f ${WRKSRC}/src/*.o

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/wterm

.include <bsd.port.mk>
