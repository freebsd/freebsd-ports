# New ports collection makefile for:	DockApp Library
# Date created:		17 July 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdockapp
PORTVERSION= 	0.4.0
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jim

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
