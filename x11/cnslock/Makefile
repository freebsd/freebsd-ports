# New ports collection makefile for:	cnslock
# Date created:				10 May 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	cnslock
PORTVERSION=	1.02
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.dockapps.com/download.php/id/181/ \
		ftp://ftp.nsu.ru/tmp/

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	A visual indicator of the states of the three "lock" buttons

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_X_PREFIX=	yes
USE_XPM=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
