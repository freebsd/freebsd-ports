# New ports collection makefile for:   expocity
# Date created:        Feb 2nd 2004
# Whom:                Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	expocity
PORTVERSION=	2.6.2
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.pycage.de/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1
DIST_SUBDIR=	gnome2

MAINTAINER=	barner@FreeBSD.org
COMMENT=	A metacity spin-off with Expose(tm)-like features

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

CONFLICTS=	metacity*
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
USE_GNOME=	gnomeprefix gnomehack gnomehier gconf2 libglade2
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

.include <bsd.port.mk>
