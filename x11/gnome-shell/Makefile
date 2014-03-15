# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/x11/gnome-shell/Makefile,v 1.16 2010/11/20 15:05:25 kwm Exp $

PORTNAME=	gnome-shell
PORTVERSION=	2.31.2
PORTREVISION=	1
CATEGORIES=	x11 gnome
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

BROKEN=		Doesn't build

USE_XORG=	x11 xfixes sm
USES=		gettext gmake tar:bzip2
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 gconf2 gnomemenus \
		gnomedesktop ltverhack libgnomeui librsvg2
USE_GSTREAMER=	theora
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/js -I${LOCALBASE}/include/nspr

GCONF_SCHEMAS=	gnome-shell.schemas

MAN1=		gnome-shell.1

NO_STAGE=	yes
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
