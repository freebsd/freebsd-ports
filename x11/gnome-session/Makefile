# New ports collection makefile for:	gnomesession
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomesession
PORTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://people.FreeBSD.org/~marcus/:local \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	sources/gnome-session/2.6 \
		    	marcus/:local
DISTNAME=	gnome-session-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${SPLASH_IMG}:local
DIST_SUBDIR=	gnome2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 2 desktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier intlhack lthack libgnomeui
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ARGS=	--with-halt-command=/sbin/shutdown \
		--with-reboot-command=/sbin/shutdown
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=	gnome-session.1 gnome-smproxy.1 gnome-wm.1 session-properties.1 \
	gnome-session-save.1
MAN5=	default.session.5

SPLASH_IMG=	gnome-splash04-12.png

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${SPLASH_IMG} ${WRKDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${SPLASH_IMG} \
		${PREFIX}/share/gnome/pixmaps/splash/gnome-splash.png

.include <bsd.port.mk>
