# New ports collection makefile for:	gnomesession
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomesession
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	sources/gnome-session/2.4 \
		    	marcus/:local
DISTNAME=	gnome-session-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		splash.png:local
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 2 desktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomehier libgnomeui
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=	gnome-session.1 gnome-smproxy.1 gnome-wm.1 session-properties.1 \
	gnome-session-save.1
MAN5=	default.session.5

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/splash.png ${WRKDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/splash.png \
		${PREFIX}/share/gnome/pixmaps/splash/gnome-splash.png

.include <bsd.port.mk>
