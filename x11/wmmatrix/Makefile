# New ports collection makefile for:	wmMatrix
# Date created:		13 October 1999
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	wmmatrix
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/
DISTNAME=	wmMatrix-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DockApp that runs a version of the xmatrix screenhack

PLIST_FILES=	bin/wmmatrix
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	clean all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmMatrix ${PREFIX}/bin/wmmatrix

.include <bsd.port.mk>
