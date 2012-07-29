# New ports collection makefile for:	xinit
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xinit
PORTVERSION=	1.3.2
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Window System initializer

LICENSE=	MIT

XORG_CAT=	app
USE_XORG=	x11

PLIST_FILES=	bin/startx bin/xinit lib/X11/xinit/xinitrc
PLIST_DIRS=	lib/X11/xinit

MAN1=		startx.1 xinit.1

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|hexdump|/usr/bin/hexdump|' ${WRKSRC}/startx.cpp
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/man/xinit.man

.include <bsd.port.mk>
