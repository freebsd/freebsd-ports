# Ports collection Makefile for:	gswitchit
# Date created:				15 May 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gswitchit
PORTVERSION=	2.5.0
PORTREVISION=	4
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gswitchit

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A simple keyboard state indicator and switcher for GNOME Desktop

LIB_DEPENDS=	xklavier.7:${PORTSDIR}/x11/libxklavier
RUN_DEPENDS=	${X11BASE}/lib/X11/xkb/rules/xfree86.xml:${PORTSDIR}/x11/XFree86-4-clients

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
