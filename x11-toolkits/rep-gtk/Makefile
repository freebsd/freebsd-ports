# New ports collection makefile for:   rep-gtk
# Version required:    0.9.1
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	rep-gtk-0.9.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://rep-gtk.sourceforge.net/pub/rep-gtk/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
.if !defined(NOGNOME)
LIB_DEPENDS+=	glade.2:${PORTSDIR}/devel/libglade \
		gnome.3:${PORTSDIR}/x11/gnomelibs
.endif
BUILD_DEPENDS=	rep:${PORTSDIR}/lang/librep

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
.if defined(NOGNOME)
CONFIGURE_ARGS=	--without-libglade --without-gnome
.else
CONFIGURE_ARGS=	--with-gnome
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
