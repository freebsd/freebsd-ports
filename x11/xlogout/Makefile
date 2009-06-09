# New ports collection makefile for:   xlogout
# Date created:                1998-11-06
# Whom:                        Christian Weisgerber <naddy@mips.rhein-neckar.de>
#
# $FreeBSD$
#

PORTNAME=	xlogout
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tu-darmstadt.de/pub/X11/other/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Simple logout button

WRKSRC=		${WRKDIR}/xlogout
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAKE_JOBS_SAFE=	yes
MAN1=		xlogout.1

PLIST_FILES=	bin/xlogout \
		lib/X11/app-defaults/XLogout

.include <bsd.port.mk>
