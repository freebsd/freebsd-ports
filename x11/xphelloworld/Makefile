# New ports collection makefile for:	xphelloworld
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xphelloworld
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Sends a test page to an Xprint printer

XORG_CAT=	app
USE_XORG=	x11 xaw8 xprintutil xp xprintapputil xt

PLIST_FILES=	bin/xphelloworld \
		bin/xpsimplehelloworld \
		bin/xpxthelloworld

MAN1=		xphelloworld.1 \
		xpsimplehelloworld.1 \
		xpxthelloworld.1

post-build:
	${REINPLACE_CMD} \
		-e "s/__appmansuffix__/1/g" \
		-e "s/__miscmansuffix__/7/g" \
		-e "s/__libmansuffix__/3Xp/g" \
		${WRKSRC}/xphelloworld/xphelloworld.man \
		${WRKSRC}/xpsimplehelloworld/xpsimplehelloworld.man \
		${WRKSRC}/xpxmhelloworld/xpxmhelloworld.man \
		${WRKSRC}/xpxthelloworld/xpxthelloworld.man

.include <bsd.port.mk>
