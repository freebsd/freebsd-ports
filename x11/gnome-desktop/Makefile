# New ports collection makefile for:	gnomedesktop
# Date created:				13 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomedesktop
PORTVERSION=	2.4.1.1
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-desktop/2.4
DISTNAME=	gnome-desktop-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for GNOME 2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libgnomeui
GNOME_DESKTOP_VERSION=2
USE_GMAKE=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-gnome-distributor="FreeBSD GNOME Project" \
		--with-kde-datadir=${LOCALBASE}/share
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	gnome-about.1

.include <bsd.port.mk>
