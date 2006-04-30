# New ports collection makefile for:	gnomesession
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnomesession/Makefile,v 1.83 2006/04/24 03:18:23 marcus Exp $
#

PORTNAME=	gnomesession
PORTVERSION=	2.14.1
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		${MASTER_SITE_LOCAL:S/$/:local/} \
		http://people.FreeBSD.org/~adamw/images/gnome_splashes/2.12/:local
MASTER_SITE_SUBDIR=	sources/gnome-session/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/} \
		    	adamw/:local
DISTNAME=	gnome-session-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${SPLASHES}:local
DIST_SUBDIR=	gnome2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 2 desktop

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop
GNOME_DESKTOP_VERSION=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		gnome-session.1 gnome-wm.1 session-properties.1 \
		gnome-session-save.1
MAN5=		default.session.5
GCONF_SCHEMAS=	gnome-session.schemas

SPLASHES=	freebsd-splashes-gnome-2.12.1.tar

post-extract:
	cd ${WRKDIR} && ${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${SPLASHES}

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnome-session/gnome-splash.png \
		${PREFIX}/share/gnome/pixmaps/splash/original-gnome-splash.png
#	${INSTALL_DATA} ${WRKDIR}/freebsd-splashes-gnome-2.12/domix-splash-2.12.png \
#		${PREFIX}/share/gnome/pixmaps/splash/gnome-splash.png
.for splash in MaMBaNgGaoX-2.12.png adamw-piggy-2.12.png adamw-trophy-2.12.png andreas-slogan-2.12.png andreas-splash-2.12.png domix-splash-2.12.png domix-splash2-2.12.png mumija-2.12.png mumija2-2.12.png mumija3-2.12.png tremulant-2.12.png tremulant-blood-2.12.png tremulant-brushed-metal-2.12.png
	${INSTALL_DATA} ${WRKDIR}/freebsd-splashes-gnome-2.12/${splash} \
		${PREFIX}/share/gnome/pixmaps/splash
.endfor

.include <bsd.port.mk>
