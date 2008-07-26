# New ports collection makefile for:	printscreen
# Date created:	25 Jan 2006
# Whom:	Alex Kozlov <spam@rm-rf.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	printscreen
PORTVERSION=	1.0
CATEGORIES=	x11
DISTFILES=

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	Simple screenshot program for X11

RUN_DEPENDS=	xwd:${PORTSDIR}/x11/xwd \
		xwdtopnm:${PORTSDIR}/graphics/netpbm

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/printscreen

do-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/printscreen.in ${PREFIX}/bin/printscreen

.include <bsd.port.mk>
