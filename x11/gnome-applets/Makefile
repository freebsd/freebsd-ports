# New ports collection makefile for:	gnomeapplets2
# Date created:				26th May 2000
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeapplets2
PORTVERSION=	2.0.4
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-applets/2.0
DISTNAME=	gnome-applets-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	panel-applet-2.0:${PORTSDIR}/x11/gnomepanel \
		gailutil.17:${PORTSDIR}/x11-toolkits/gail \
		gtop-2.0:${PORTSDIR}/devel/libgtop2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
PLIST_SUB=      BATTERY="@comment "
.else
PLIST_SUB=      BATTERY=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
