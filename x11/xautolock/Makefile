# Created by: Eric Blood <eblood@cs.unr.edu>
# $FreeBSD$

PORTNAME=	xautolock
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SUNSITE/X11/screensavers

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Activate xlock after a user defined time of inactivity

USES=		tar:tgz imake gmake		# gmake is needed for -jX builds
USE_XORG=	x11 xext xscrnsaver

OPTIONS_DEFINE=	XLOCK
OPTIONS_DEFAULT=XLOCK
XLOCK_DESC=	Force dependency on x11/xlockmore

XLOCK_RUN_DEPENDS=	xlock:x11/xlockmore

PLIST_FILES=	bin/xautolock man/man1/xautolock.1.gz

.include <bsd.port.mk>
