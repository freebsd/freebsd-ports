# New ports collection makefile for:	gmessage
# Date created:			Sun Jul 18 1999
# Whom:				domi@saargate.de
#
# $FreeBSD$
#

PORTNAME=	gmessage
PORTVERSION= 	0.2
CATEGORIES=	x11
MASTER_SITES=	http://www.math.uni-goettingen.de/dadler/gmessage/

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
