# New ports collection makefile for:	fbsd-icons
# Date created:		Sat Jun 14 09:43:24 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	fbsd-icons
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of icons related to the FreeBSD project

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
		${MKDIR} ${X11BASE}/icons
		( cd ${X11BASE}/icons; ${TAR} --no-same-owner --no-same-permissions -xzf ${DISTDIR}/fbsd-icons.tar.gz )

.include <bsd.port.mk>
