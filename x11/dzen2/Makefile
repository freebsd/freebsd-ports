# New ports collection makefile for:   dzen2
# Date created:        May 26 2008
# Whom:                Morten Slot Kristensen
#
# $FreeBSD$
#

PORTNAME=	dzen2
PORTVERSION=	0.8.5
CATEGORIES=	x11
MASTER_SITES=	http://gotmor.googlepages.com/

MAINTAINER=	msk@nullpointer.dk
COMMENT=	General purpose messaging, notification and menuing program for X11

USE_XORG=	x11

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g'       \
		${WRKSRC}/config.mk

.include <bsd.port.mk>
