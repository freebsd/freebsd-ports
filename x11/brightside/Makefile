# New ports collection makefile for:   brightide
# Date created:        02 July 2004
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	brightside
PORTVERSION=	1.4.0
CATEGORIES=	x11
MASTER_SITES=	http://home.jesus.ox.ac.uk/~ecatmur/brightside/download/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A tool to add reactivity to the edges and corners of the GNOME desktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix gnomehack libwnck libgnomeui
CONFIGURE_ARGS=	--enable-tray-icon
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	brightside.schemas

.include <bsd.port.mk>
