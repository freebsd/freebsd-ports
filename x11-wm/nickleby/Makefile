# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	nickleby
PORTVERSION=	2.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Simple window manager

MAKE_ENV=	X11BASE=${LOCALBASE}
USE_XORG=	x11

MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_MAN="${INSTALL_MAN}"
PLIST_FILES=	bin/nickleby \
		man/man1/nickleby.1.gz

.include <bsd.port.mk>
