# New ports collection makefile for:	xcursorgen
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcursorgen
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Create an X cursor file from a collection of PNG images

LICENSE=	MIT

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

XORG_CAT=	app
USE_XORG=	x11 xcursor xextproto

PLIST_FILES=	bin/xcursorgen

MAN1=		xcursorgen.1

post-patch:
	${REINPLACE_CMD} -e 's|libpng12|libpng14|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
