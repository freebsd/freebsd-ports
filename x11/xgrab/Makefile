# New ports collection makefile for:    xgrab
# Date created:         27 February 1995
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	xgrab
PORTVERSION=	2.41
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
DISTNAME=	${PORTNAME}sc.2_41
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>
.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	xrdb:${PORTSDIR}/x11/XFree86-4-clients
.endif

USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f
# "make depend" blows up
XMKMF=		xmkmf

.if !defined(DISPLAY) || ${DISPLAY} == ""
BROKEN=		"Requires an active X session (and DISPLAY variable) to run xrdb.  Please compile this while running X."
.endif

MAN1=		xgrab.1 xgrabsc.1

.include <bsd.port.post.mk>
