# New ports collection makefile for:	gnome2wmaker
# Date Created:				18 September 1999
# Whom:				 	Jeremy Lea <reg@shale.csir.co.za>
#
# $FreeBSD$
#

PORTNAME=	gnome2wmaker
PORTVERSION= 	1.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ulli.linuxbox.com/gnome2wmaker/

MAINTAINER=     reg@FreeBSD.org

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore \
		wmaker:${PORTSDIR}/x11-wm/windowmaker

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX}
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
