# New ports collection makefile for:	x11-fm/libfm
# Date created:				23 Sept 2010
# Whom:					Kris Moore <kmoore@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libfm
PORTVERSION=	0.1.12
CATEGORIES=	x11
MASTER_SITES=	SF/pcmanfm/PCManFM2%20%2B%20Libfm%20%28experimental%29/libfm%20%28required%20by%20PCManFM%29/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	The libFM backend library to PCManFM.

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		menu-cache.1:${PORTSDIR}/x11/menu-cache

USE_GNOME=	gnomehack gtk20 pkgconfig
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_FAM=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--prefix=${LOCALBASE} --sysconfdir=${LOCALBASE}/etc

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

pre-install:
	cd ${WRKDIR}/libfm-${PORTVERSION} && ${CHMOD} 755 install-sh

.include <bsd.port.post.mk>
