# New ports collection makefile for:   	wscan
# Date created:				10 December 2001
# Whom:                			Jim Binkley <jrb@cs.pdx.edu>
#
# $FreeBSD$
#

PORTNAME=	wscan
PORTVERSION=	1.00
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/mobile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A 802.11 wireless visual signal strength meter

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

WRKSRC=		$(WRKDIR)/wscan
USE_XLIB=	yes
MAN1=		wscan.1

post-install:
	${STRIP_CMD} ${PREFIX}/bin/wscan

.include <bsd.port.mk>
