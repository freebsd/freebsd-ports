# New ports collection makefile for:	gnomeapplets
# Date created:				26th May 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeapplets
PORTVERSION= 	1.2.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-applets
DISTNAME=	gnome-applets-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	panel_applet.4:${PORTSDIR}/x11/gnomecore \
		xml.5:${PORTSDIR}/textproc/libxml \
		ghttp.1:${PORTSDIR}/www/libghttp \
		esd.2:${PORTSDIR}/audio/esound \
		gtop.1:${PORTSDIR}/devel/libgtop

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
