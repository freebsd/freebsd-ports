# New ports collection makefile for:   metacity
# Date created:        21 May 2002
# Whom:                Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#    $MCom: ports/x11-wm/metacity/Makefile,v 1.78 2006/04/15 01:51:15 mezz Exp $
#

PORTNAME=	metacity
PORTVERSION=	2.14.3
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A window manager for the adult in you

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

CONFLICTS=	expocity-[0-9]*
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gconf2
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-render
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	metacity.schemas

MAN1=		metacity-theme-viewer.1 metacity-window-demo.1 \
		metacity.1

.include <bsd.port.mk>
