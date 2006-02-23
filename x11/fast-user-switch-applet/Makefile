# New ports collection makefile for:	user-selector-applet
# Date created:		8 May 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fast-user-switch-applet
PORTVERSION=	0.2.4
CATEGORIES=	x11 gnome
MASTER_SITES=	http://ignore-your.tv/downloads/fusa/ \
		${MASTER_SITE_LOCAL:S/%SUBDIR%/bland/}
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Fast user switching applet for GNOME

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk20 gnomepanel
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gdm-config=${X11BASE}/etc/gdm/gdm.conf
USE_REINPLACE=	yes

GCONF_SCHEMAS=	fast-user-switch-applet.schemas
INSTALLS_OMF=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|\$$"\$$|"$$|' ${WRKSRC}/configure

.include <bsd.port.mk>
