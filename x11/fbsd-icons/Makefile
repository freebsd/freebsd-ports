# New ports collection makefile for:	fbsd-icons
# Version required:	1.0
# Date created:		Sat Jun 14 09:43:24 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.4 1998/08/05 09:31:42 asami Exp $
#

DISTNAME=	fbsd-icons
PKGNAME=	fbsd-icons-1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	andreas@FreeBSD.ORG

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
		${MKDIR} ${X11BASE}/icons
		( cd ${X11BASE}/icons; ${TAR} -xzf ${DISTDIR}/fbsd-icons.tar.gz )

.include <bsd.port.mk>
