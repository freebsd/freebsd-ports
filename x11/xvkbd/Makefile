# New ports collection makefile for:	xvkbd
# Date created:		26 November 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xvkbd
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://member.nifty.ne.jp/tsato/xvkbd/

MAINTAINER=	roam@FreeBSD.org

.if	defined(WITH_XAW3D)
BUILD_DEPENDS=	${X11BASE}/lib/libXaw3d.a:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

USE_IMAKE=	yes

pre-fetch:
		@${ECHO} "Define WITH_XAW3D for Xaw3d support."

.if	defined(WITH_XAW3D)
post-patch:
		${PERL} -pi.fbsd -e 's/XCOMM define XAW3D/#define XAW3D/' ${WRKSRC}/Imakefile
.endif

.include <bsd.port.mk>
