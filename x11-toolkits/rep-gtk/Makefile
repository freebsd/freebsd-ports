# New ports collection makefile for:   rep-gtk
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rep-gtk
PORTVERSION=	0.15
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/rep-gtk/0.15
#DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ binding for rep Lisp interpreter

LIB_DEPENDS=	rep.12:${PORTSDIR}/lang/librep

PLIST_SUB=	GNUHOST=${ARCH}-pc-freebsd${OSREL:C/\..*//}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
.undef WITHOUT_GNOME
.undef WITHOUT_ALL
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibglade}!=""
USE_GNOME+=	libglade
PKGNAMESUFFIX=	-gnome
CONFIGURE_ARGS=	--with-gnome --with-libglade --with-gdk-pixbuf \
		--with-gnome-canvas-pixbuf
.else
CONFIGURE_ARGS=	--without-libglade --without-gnome --without-gdk-pixbuf \
		--without-gnome-canvas-pixbuf
.endif

.include <bsd.port.post.mk>
