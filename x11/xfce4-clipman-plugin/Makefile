# New ports collection makefile for:	xfce4-clipman-plugin
# Date created:		23 November 2003
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-clipman-plugin
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	XFce 4 clipboard module for xfce4-panel

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel libgui libutil
USE_XLIB=	yes

.include <bsd.port.mk>
