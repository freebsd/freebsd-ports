# New ports collection makefile for:   xfishtank
# Date created:        24th April 1997
# Whom:                jacs
#
# $FreeBSD$
#

PORTNAME=	xfishtank
PORTVERSION=	2.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=	jacs@gnome.co.uk
COMMENT=	Make fish swim in the background of your screen

PLIST_FILES=	bin/xfishtank
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xfishtank2.0

post-patch:
	cd  ${WRKDIR}/xfishtank2.0; make clean

.include <bsd.port.mk>
