# New ports collection makefile for:	gnomecore
# Date created:				17 March 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnomecore
PORTVERSION= 	1.2.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-core
DISTNAME=	gnome-core-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	capplet.4:${PORTSDIR}/sysutils/gnomecontrolcenter \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		xml.5:${PORTSDIR}/textproc/libxml

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-kde-datadir=${LOCALBASE}/share
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gnome-session.1 gnome-wm.1 save-session.1
MAN5=		default.session.5

.include <bsd.port.mk>
