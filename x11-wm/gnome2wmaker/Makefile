# New ports collection makefile for:	gnome2wmaker
# Date Created:				18 September 1999
# Whom:				 	Jeremy Lea <reg@shale.csir.co.za>
#
# $FreeBSD$
#

PORTNAME=	gnome2wmaker
PORTVERSION=	1.2
CATEGORIES=	x11-wm gnome
MASTER_SITES=	http://ulli.on.openave.net/gnome2wmaker/

MAINTAINER=	reg@FreeBSD.org

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList
RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
