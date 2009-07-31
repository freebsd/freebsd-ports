# New ports collection makefile for:   wterm
# Date created:		25 February 1999
# Whom:		 	Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wterm
PORTVERSION=	6.2.9
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	adam-ports@blacktabby.org
COMMENT=	A color vt102 terminal emulator with transparency support

BUILD_DEPENDS=	${LOCALBASE}/lib/libWINGs.a:${PORTSDIR}/x11-wm/windowmaker

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-transparency --enable-xpm-background \
		--disable-delete-key --disable-backspace-key \
		--enable-next-scrollbar --enable-utmp --enable-wtmp \
		--enable-menubar --enable-graphics --with-term=xterm-color \
		--with-xpm-includes=${LOCALBASE} --with-xpm-library=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/WINGs"

MAN1=		wterm.1
PLIST_FILES=	bin/wterm

post-extract:
	${RM} -f ${WRKSRC}/config.cache
	${RM} -f ${WRKSRC}/src/*.o

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/wterm

.include <bsd.port.mk>
