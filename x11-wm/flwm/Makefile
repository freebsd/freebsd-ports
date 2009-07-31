# New ports collection makefile for:   	flwm
# Date created:				12 February 1999
# Whom:                			Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	flwm
PORTVERSION=	1.02
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The Fast Light Window Manager

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_XORG=	x11 xt
GNU_CONFIGURE=	yes

MAN1=		flwm.1
PLIST_FILES=	bin/flwm

post-patch:
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
