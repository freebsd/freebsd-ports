# New ports collection makefile for:	startup-notification
# Date created:				14 November 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	startup-notification
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.5
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library that supports startup notification spec from freedesktop.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
