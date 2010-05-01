# New ports collection makefile for:	xinit
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xinit
PORTVERSION=	1.2.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Window System initializer

XORG_CAT=	app
USE_XORG=	x11

PLIST_FILES=	bin/startx bin/xinit lib/X11/xinit/xinitrc
PLIST_DIRS=	lib/X11/xinit

MAN1=		startx.1 xinit.1

post-patch:
	@${REINPLACE_CMD} -e 's|hexdump|/usr/bin/hexdump|' ${WRKSRC}/startx.cpp

.include <bsd.port.mk>
