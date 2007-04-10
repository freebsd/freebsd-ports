# New ports collection makefile for:	yelp
# Date created:				18 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/yelp/Makefile,v 1.110 2007/03/14 17:45:40 marcus Exp $
#

PORTNAME=	yelp
PORTVERSION=	2.18.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A help browser for the GNOME 2 desktop

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_GECKO=	firefox xulrunner firefox-devel<->firefox
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui gnomedocutils \
		libgnomeprintui
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-mozilla=${GECKO}
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	yelp.schemas

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
