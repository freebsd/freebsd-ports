# Ports collection Makefile for:	powershell
# Date created:				6 May 2000
# Whom:					Scott A. Moberly <smoberly@xavier.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	powershell
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A terminal emulator for the X11

USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs
USE_AUTOCONF_VER=	213
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include  `${IMLIB_CONFIG} --cflags`" \
		LDFLAGS="-L${LOCALBASE}/lib  `${IMLIB_CONFIG} --libs`"
ALL_TARGET=	${PORTNAME}

.include <bsd.port.mk>
