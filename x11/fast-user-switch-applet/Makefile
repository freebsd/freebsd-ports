# New ports collection makefile for:	user-selector-applet
# Date created:		8 May 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/fast-user-switch-applet/Makefile,v 1.31 2008/03/10 01:00:42 mezz Exp $
#

PORTNAME=	fast-user-switch-applet
PORTVERSION=	2.22.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Fast user switching applet for GNOME

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gtk20 gnomepanel
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gdm-config=${LOCALBASE}/etc/gdm/custom.conf \
		--with-gdm-setup=${LOCALBASE}/sbin/gdmsetup

GCONF_SCHEMAS=	fast-user-switch-applet.schemas
INSTALLS_OMF=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|\$$"\$$|"$$|' ${WRKSRC}/configure

.include <bsd.port.mk>
