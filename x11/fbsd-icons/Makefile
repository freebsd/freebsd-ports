# New ports collection makefile for:	fbsd-icons
# Version required:	1.0
# Date created:		Sat Jun 14 09:43:24 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.2 1997/06/29 10:50:38 obrien Exp $
#

DISTNAME=	fbsd-icons
PKGNAME=	fbsd-icons-1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	andreas@FreeBSD.ORG

USE_X11=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
		${MKDIR} ${X11BASE}/icons
		( cd ${X11BASE}/icons; ${EXTRACT_CMD} xzf ${DISTDIR}/fbsd-icons.tar.gz )

.include <bsd.port.mk>
