# New ports collection makefile for:   rep-gtk
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rep-gtk
PORTVERSION=	0.10
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://rep-gtk.sourceforge.net/pub/rep-gtk/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
.if !defined(NOGNOME)
LIB_DEPENDS+=	glade.3:${PORTSDIR}/devel/libglade \
		gnome.4:${PORTSDIR}/x11/gnomelibs
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

.if defined(NOGNOME)
PLIST=		${PKGDIR}/PLIST.nognome
.endif

.include <bsd.port.mk>
