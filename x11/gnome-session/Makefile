# New ports collection makefile for:	gnomesession
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomesession
PORTVERSION=	2.10.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		${MASTER_SITE_LOCAL:S/$/:local/} \
		http://people.FreeBSD.org/~pav/:local
MASTER_SITE_SUBDIR=	sources/gnome-session/2.10 \
		    	pav/:local
DISTNAME=	gnome-session-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${SPLASHES}:local
DIST_SUBDIR=	gnome2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 2 desktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		gnome-session.1 gnome-smproxy.1 gnome-wm.1 \
		session-properties.1 gnome-session-save.1
MAN5=		default.session.5
GCONF_SCHEMAS=	gnome-session.schemas

SPLASHES=	freebsd-splashes-gnome-2.10.tar

post-extract:
	cd ${WRKDIR} && ${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${SPLASHES}

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnome-session/gnome-splash.png \
		${PREFIX}/share/gnome/pixmaps/splash/original-gnome-splash.png
	${INSTALL_DATA} ${WRKDIR}/freebsd-splashes-gnome-2.10/franz_klammer-2.png \
		${PREFIX}/share/gnome/pixmaps/splash/gnome-splash.png
.for splash in adamw.png banana_flex.png franco_malatacca.jpg franz_klammer-1.png franz_klammer-3.png radek.png
	${INSTALL_DATA} ${WRKDIR}/freebsd-splashes-gnome-2.10/${splash} \
		${PREFIX}/share/gnome/pixmaps/splash
.endfor

.include <bsd.port.mk>
