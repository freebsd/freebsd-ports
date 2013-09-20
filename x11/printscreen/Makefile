# Created by: Alex Kozlov <spam@rm-rf.kiev.ua>
# $FreeBSD$

PORTNAME=	printscreen
PORTVERSION=	1.4
CATEGORIES=	x11
DISTFILES=

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Simple screenshot program for X11

RUN_DEPENDS=	xwd:${PORTSDIR}/x11/xwd \
		xwdtopnm:${PORTSDIR}/graphics/netpbm

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/printscreen

NO_STAGE=	yes
do-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/printscreen.in ${PREFIX}/bin/printscreen

.include <bsd.port.mk>
