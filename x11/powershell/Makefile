# Ports collection Makefile for:	powershell
# Date created:				6 May 2000
# Whom:					Scott A. Moberly <smoberly@xavier.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	powershell
PORTVERSION=	0.8
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	smoberly@xavier.dyndns.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gdk_imlib:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
USE_AUTOCONF=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/gnome

ALL_TARGET=	powershell

MAKE_ENV=	${CONFIGURE_ENV}

.include <bsd.port.mk>
