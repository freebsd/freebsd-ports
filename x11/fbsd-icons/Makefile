# New ports collection makefile for:	fbsd-icons
# Version required:	1.0
# Date created:		Sat Jun 14 09:43:24 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id$
#

DISTNAME=	fbsd-icons
PKGNAME=	fbsd-icons-1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	andreas@FreeBSD.ORG

USE_X11=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes

do-install:
		mkdir -p ${X11BASE}/icons
		( cd ${X11BASE}/icons; tar xzf ${DISTDIR}/fbsd-icons.tar.gz )

.include <bsd.port.mk>
