# New ports collection makefile for:   metacity
# Date created:        21 May 2002
# Whom:                Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#   $MCom: ports/x11-wm/metacity/Makefile,v 1.145 2009/03/26 17:34:42 marcus Exp $
#

PORTNAME=	metacity
PORTVERSION=	2.26.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A window manager for the adult in you

BUILD_DEPENDS=  zenity:${PORTSDIR}/x11/zenity
LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=    zenity:${PORTSDIR}/x11/zenity

CONFLICTS=	expocity-[0-9]*
USE_BZIP2=	yes
USE_XORG=	x11 xcomposite xdamage
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomeprefix intlhack gnomehack gconf2 ltverhack gtk20
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	metacity.schemas

MAN1=		metacity-message.1 metacity-theme-viewer.1 \
		metacity-window-demo.1 metacity.1

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
