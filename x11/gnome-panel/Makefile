# New ports collection makefile for:	gnomepanel
# Date created:				27 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepanel
PORTVERSION=	2.0.11
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-panel/2.0
DISTNAME=	gnome-panel-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	wnck-1.4:${PORTSDIR}/x11-toolkits/libwnck \
		gnome-desktop-2.0:${PORTSDIR}/x11/gnomedesktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-kde-datadir=${LOCALBASE}/share \
		--with-kde-docdir=${LOCALBASE}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=	gnome-panel.1 gnome-panel-preferences.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
