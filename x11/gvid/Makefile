# Ports collection Makefile for:	gvid
# Date created:				5 June 2000
# Whom:			Scott A. Moberly <smoberly@xavier.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	gvid
PORTVERSION=	0.3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome applet to change video resolution

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

USE_X_PREFIX=	yes
USE_GNOME=	libpanel
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gvid ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gvid.gnorba ${PREFIX}/etc/CORBA/servers
	${INSTALL_DATA} ${WRKSRC}/gvid.desktop ${PREFIX}/share/gnome/applets/Utility

.include <bsd.port.mk>
