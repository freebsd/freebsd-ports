# New ports collection makefile for:	gnomeapplets2
# Date created:				26th May 2000
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeapplets2
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-applets/2.4
DISTNAME=	gnome-applets-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the Gnome 2 Desktop Environment

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomehier gnomeprefix gnomehack gnomepanel gail
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
PLIST_SUB=	BATTERY="@comment "
.else
PLIST_SUB=	BATTERY=""
.endif

.include <bsd.port.post.mk>
