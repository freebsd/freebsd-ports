# New ports collection makefile for:   rep-gtk
# Date created:        06 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rep-gtk2
PORTVERSION=	0.17
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/rep-gtk/0.17
DISTNAME=	rep-gtk-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	rep.12:${PORTSDIR}/lang/librep \
		gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui

PLIST_SUB=	GNUHOST=${ARCH}-pc-freebsd${OSREL:C/\..*//}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libglade \
		--with-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	${ARCH}-pc-freebsd${OSREL:C/\..*//}

.include <bsd.port.mk>
