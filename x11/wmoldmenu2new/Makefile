# New ports collection makefile for:	wm-oldmenu2new
# Date created:		6 September 2002
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmoldmenu2new
PORTVERSION=	20020609
CATEGORIES=	x11
MASTER_SITES=	http://largo.windowmaker.org/files/
DISTNAME=	wm-oldmenu2new
EXTRACT_SUFX=	.gz

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Script to convert WindowMaker RootMenu menus to new PropList format

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
EXTRACT_AFTER_ARGS=	> ${PORTNAME}

NOMAN=		# defined
PLIST_FILES=	bin/wmoldmenu2new

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
