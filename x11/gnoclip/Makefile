# New ports collection makefile for:	gnoclip
# Date created:				10 Apr 2002
# Whom:					Edy  <edybsd@yahoo.com.ar>
#
# $FreeBSD$
#

PORTNAME=	gnoclip
PORTVERSION=	0.1.9
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.unikol.com.pl/~adolf/

MAINTAINER=	edybsd@yahoo.com.ar

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix libpanel

ALL_TARGET=	gnoclip_applet
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnoclip_applet ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gnoclip.desktop  \
		${PREFIX}/share/gnome/applets/Utility
	${INSTALL_DATA} ${WRKSRC}/gnoclip.gnorba ${PREFIX}/etc/CORBA/servers

.include <bsd.port.mk>
