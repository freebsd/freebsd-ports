# New ports collection makefile for:   gnome-shell
# Date created:        14 Aug 2009
# Whom:                Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-shell/Makefile,v 1.11 2010/03/29 11:42:11 kwm Exp $
#

PORTNAME=	gnome-shell
PORTVERSION=	2.29.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		mutter-private.0:${PORTSDIR}/x11-wm/mutter \
		clutter-glx-1.0:${PORTSDIR}/graphics/clutter \
		gjs-gi:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
    		glxinfo:${PORTSDIR}/graphics/mesa-demos

USE_BZIP2=	yes
USE_XORG=	x11 xfixes sm
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 gconf2 gnomemenus \
		gnomedesktop ltverhack libgnomeui librsvg2
USE_GSTREAMER=	theora
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/js -I${LOCALBASE}/include/nspr"

GCONF_SCHEMAS=	gnome-shell.schemas

MAN1=		gnome-shell.1

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/gnome-shell.in
# temp hack around configure failure in 2.29.90. Fixed upstream
	@${REINPLACE_CMD} -e 's|@GETTEXT_PACKAGE@|gnome-shell|g' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
