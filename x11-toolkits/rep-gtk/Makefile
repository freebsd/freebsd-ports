# New ports collection makefile for:   rep-gtk
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rep-gtk
PORTVERSION=	0.15
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	rep.10:${PORTSDIR}/lang/librep

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
LIB_DEPENDS+=	glade.4:${PORTSDIR}/devel/libglade \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
USE_GNOMELIBS=	yes
CONFIGURE_ARGS=	--with-gnome --with-libglade --with-gdk-pixbuf \
		--with-gnome-canvas-pixbuf
.else
CONFIGURE_ARGS=	--without-libglade --without-gnome --without-gdk-pixbuf \
		--without-gnome-canvas-pixbuf
.endif

.include <bsd.port.post.mk>
