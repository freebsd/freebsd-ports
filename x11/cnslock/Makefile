# New ports collection makefile for:	cnslock
# Date created:				10 Apr 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	cnslock
PORTVERSION=	1.02
PORTREVISION=	2
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.dockapps.com/download.php/id/181/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	A visual indicator of the states of the three "lock" buttons

USE_GETOPT_LONG=yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_XPM=	yes

MAKE_ENV=	LDFLAGS="${LDFLAGS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
