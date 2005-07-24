# New ports collection makefile for:   metacity
# Date created:        21 May 2002
# Whom:                Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#

PORTNAME=	metacity
PORTVERSION=	2.10.3
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A window manager for the adult in you

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

CONFLICTS=	expocity-[0-9]*
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix intlhack gnomehack gconf2
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-render
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	metacity.schemas

MAN1=		metacity-theme-viewer.1 metacity-window-demo.1

.include <bsd.port.mk>
