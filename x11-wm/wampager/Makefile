# New ports collection makefile for: wampager
# Date created:        11 Jan 2003
# Whom:                Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wampager
PORTVERSION=	0.9.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.waimea.org/wampager/

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	A mini pager for the waimea window manager

PLIST_FILES=	bin/wampager
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wampager ${PREFIX}/bin

.include <bsd.port.mk>
