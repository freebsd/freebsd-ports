# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-xfapplet-plugin
PORTVERSION=	0.1.0
PORTREVISION=	17
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfapplet plugin for Xfce

LICENSE=	GPLv2

LIB_DEPENDS=	libpanelappletmm-2.6.so:${PORTSDIR}/x11-toolkits/libpanelappletmm

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool intlhack orbit2
USE_XFCE=	configenv libgui libutil panel

.include <bsd.port.mk>
