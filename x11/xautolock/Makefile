# Created by: Eric Blood <eblood@cs.unr.edu>
# $FreeBSD$

PORTNAME=	xautolock
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/screensavers
EXTRACT_SUFX=	.tgz

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Activate xlock after a user defined time of inactivity

USES=		imake gmake		# gmake is needed for -jX builds
USE_XORG=	x11 xext xscrnsaver

OPTIONS_DEFINE=	XLOCK
OPTIONS_DEFAULT=	XLOCK
XLOCK_DESC=	Force dependency on x11/xlockmore

XLOCK_RUN_DEPENDS=	xlock:${PORTSDIR}/x11/xlockmore

MAN1=		xautolock.1
PLIST_FILES=	bin/xautolock

.include <bsd.port.mk>
