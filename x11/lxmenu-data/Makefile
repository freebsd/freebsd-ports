# New ports collection makefile for:	lxmenu-data
# Date created:		Fri Sept 24 09:52:35 EST 2010
# Whom:			Kris Moore <kmoore@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	lxmenu-data
PORTVERSION=	0.1.1
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/lxmenu-data%20%28desktop%20menu%29/lxmenu-data%20${PORTVERSION}

MAINTAINER=	kmoore@freebsd.org
COMMENT=	Menu data used by lxpanel

USE_XORG=	x11 xmu
USE_GNOME=	intltool
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:111:env
CONFIGURE_ARGS+=--prefix=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc
USE_GMAKE=	yes

.include <bsd.port.mk>
