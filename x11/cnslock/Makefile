# New ports collection makefile for:	cnslock
# Date created:				10 Apr 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	cnslock
PORTVERSION=	1.02
PORTREVISION=	5
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.dockapps.com/files/123/181/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A visual indicator of the states of the three "lock" buttons

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

PLIST_FILES=	bin/cnslock
USE_GNOME=	gtk12
USE_XORG=	x11 xpm

MAKE_ENV=	LDFLAGS="${LDFLAGS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
