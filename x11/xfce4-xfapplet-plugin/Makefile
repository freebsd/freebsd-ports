# New ports collection makefile for:	xfapplet plugin for xfce4
# Date created:				29 April 2006
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-xfapplet-plugin
PORTVERSION=	0.1.0
PORTREVISION=	8
CATEGORIES=	x11 xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Xfapplet plugin for xfce

LIB_DEPENDS=	panelappletmm-2.6:${PORTSDIR}/x11-toolkits/libpanelappletmm

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack orbit2 pkgconfig
USE_XFCE=	configenv libgui libutil panel

.include <bsd.port.mk>
