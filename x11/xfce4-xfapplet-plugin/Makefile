# New ports collection makefile for:	xfapplet plugin for xfce4
# Date created:				29 April 2006
# Whom:					Martin Wilke (freebsd@unixfreunde.de)
#
# $FreeBSD$
#

PORTNAME=	xfce4-xfapplet-plugin
PORTVERSION=	0.1.0
CATEGORIES=	x11 xfce
MASTER_SITES=	ftp://ftp.berlios.de/pub/xfce-goodies/panel-plugins/4.4/
DIST_SUBDIR=	xfce4

MAINTAINER=	freebsd@unixfreunde.de
COMMENT=	Xfapplet plugin for xfce

LIB_DEPENDS=	panelappletmm-2.6:${PORTSDIR}/x11-toolkits/libpanelappletmm

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack orbit2 pkgconfig
USE_XFCE=	configenv libgui libutil panel
USE_XLIB=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11-wm/xfce4/bsd.xfce.mk"
.include <bsd.port.post.mk>
