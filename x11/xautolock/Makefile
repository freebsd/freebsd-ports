# New ports collection makefile for:	xautolock
# Date created:		20 Jul 1996
# Whom:			Eric Blood <eblood@cs.unr.edu>
#
# $FreeBSD$
#

PORTNAME=	xautolock
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/screensavers
EXTRACT_SUFX=	.tgz

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Used to activate xlock after a user defined time of inactivity

OPTIONS=	XLOCK "Force dependency on x11/xlockmore" on

.include <bsd.port.options.mk>

.if defined(WITH_XLOCK)
RUN_DEPENDS+=	xlock:${PORTSDIR}/x11/xlockmore
.endif

USE_IMAKE=	yes
USE_XORG=	x11 xext xscrnsaver
MAN1=		xautolock.1
PLIST_FILES=	bin/xautolock

.include <bsd.port.mk>
