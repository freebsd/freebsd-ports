# New ports collection makefile for:   wmg
# Date created:        27 August 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

PORTNAME=	wmg
PORTVERSION=	0.15.0
CATEGORIES=	x11-wm gnome
MASTER_SITES=	http://ductape.net/~reeve/downloads/ \
		http://www.geocities.com/SiliconValley/Screen/4079/downloads/
DISTNAME=	wmG-${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gdk_imlib.5:${PORTSDIR}/graphics/imlib \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		esd.2:${PORTSDIR}/audio/esound \
		gnome.4:${PORTSDIR}/x11/gnomelibs

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
