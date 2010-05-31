# New ports collection makefile for:	gnometerminal
# Date created:				1 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-terminal/Makefile,v 1.132 2010/04/28 02:58:55 mezz Exp $
#

PORTNAME=	gnome-terminal
PORTVERSION=	2.30.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 2 Desktop

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

USE_GETTEXT=	yes
USE_BZIP2=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_XORG=	sm
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 vte gnomedocutils \
		libgnome
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-terminal.schemas

post-patch:
	@${TOUCH} -f ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
