# New ports collection makefile for:	xcalc
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcalc
PORTVERSION=	1.0.4.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Scientific calculator for X

RUN_DEPENDS=	font-misc-misc>=1.1.2:${PORTSDIR}/x11-fonts/font-misc-misc \
				font-adobe-100dpi>=1.0.3:${PORTSDIR}/x11-fonts/font-adobe-100dpi \
				font-alias>=1.0.3:${PORTSDIR}/x11-fonts/font-alias \
				xbitmaps>=1.1.0:${PORTSDIR}/x11/xbitmaps

XORG_CAT=	app
USE_XORG=	xt xaw

MAN1=		xcalc.1

.include <bsd.port.mk>
