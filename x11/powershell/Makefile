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

USE_X_PREFIX=	yes
USE_GNOME=	yes
IMLIB_CONFIG?=	${X11BASE}/bin/imlib-config
USE_AUTOCONF=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include `${IMLIB_CONFIG} --cflags`" \
		LDFLAGS="-L${LOCALBASE}/lib `${IMLIB_CONFIG} --libs`"
ALL_TARGET=	powershell

.include <bsd.port.mk>
