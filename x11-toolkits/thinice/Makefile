# New ports collection makefile for:	thinice
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thinice
PORTVERSION= 	1.0.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.ing.umu.se/~stric/theme/
DISTNAME=	gtk-${PORTNAME}-theme-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
