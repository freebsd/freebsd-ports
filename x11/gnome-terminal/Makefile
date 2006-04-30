# New ports collection makefile for:	gnometerminal
# Date created:				1 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnometerminal/Makefile,v 1.69 2006/04/13 07:52:41 bland Exp $
#

PORTNAME=	gnometerminal
PORTVERSION=	2.14.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-terminal/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-terminal-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 2 Desktop

USE_GETTEXT=	yes
USE_BZIP2=	yes
INSTALLS_OMF=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui vte
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-terminal.schemas

.include <bsd.port.mk>
