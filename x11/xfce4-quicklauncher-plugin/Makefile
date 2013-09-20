# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-quicklauncher-plugin
PORTVERSION=	1.9.4
PORTREVISION=	15
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Quicklauncher plugin for Xfce

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libgui panel

NO_STAGE=	yes
.include <bsd.port.mk>
