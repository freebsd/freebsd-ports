# New ports collection makefile for:   mutter
# Date created:        14 Aug 2009
# Whom:                Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/x11-wm/mutter/Makefile,v 1.6 2009/10/07 22:59:24 kwm Exp $
#

PORTNAME=	mutter
PORTVERSION=	2.28.0
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window and compositing manager based on Clutter

BUILD_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
		${LOCALBASE}/share/gir-1.0/Gtk-2.0.gir:${PORTSDIR}/x11-toolkits/gir-repository-gtk20
LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		clutter-glx-1.0:${PORTSDIR}/graphics/clutter
RUN_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
		${LOCALBASE}/share/gir-1.0/Gtk-2.0.gir:${PORTSDIR}/x11-toolkits/gir-repository-gtk20

USE_BZIP2=	yes
USE_XORG=	x11 xext xrandr xcomposite xcursor xinerama ice sm
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 gconf2 ltverhack
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	mutter.schemas

MAN1=		mutter-message.1 mutter-theme-viewer.1 \
		mutter-window-demo.1 mutter.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
	    	${WRKSRC}/configure

.include <bsd.port.post.mk>
