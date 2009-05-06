# New ports collection makefile for:	screenshooter plugin for xfce4
# Date created:				29 April 2006
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-screenshooter-plugin
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-screenshooter/
DISTNAME=	xfce4-screenshooter-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Desktop Screenshot plugin for xfce

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel
MAN1=		xfce4-screenshooter.1

.include <bsd.port.mk>
