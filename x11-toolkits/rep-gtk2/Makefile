# New ports collection makefile for:   rep-gtk
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rep-gtk
PORTVERSION=	0.13a
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		rep.9:${PORTSDIR}/lang/librep
.if !defined(WITHOUT_GNOME)
LIB_DEPENDS+=	glade.4:${PORTSDIR}/devel/libglade \
		gnome.4:${PORTSDIR}/x11/gnomelibs \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
.endif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
.if defined(WITHOUT_GNOME)
CONFIGURE_ARGS=	--without-libglade --without-gnome --without-gdk-pixbuf \
		--without-gnome-canvas-pixbuf
PLIST_SUB+=	GNOME:="@comment "
.else
CONFIGURE_ARGS=	--with-gnome --with-libglade --with-gdk-pixbuf \
		--with-gnome-canvas-pixbuf
PLIST_SUB+=	GNOME:=""
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
