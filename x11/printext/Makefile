# New ports collection makefile for:   PrintExt
# Date Created:			4 May 2004
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PrintExt
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/~xorg/X11R6.7.0/src/
DISTNAME=	X11R6.7.0-src1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Header files for the X Print Extension

CONFLICTS=	XFree86-libraries-*

PREFIX?=	${X11BASE}
DIST_SUBDIR=	xorg
WRKSRC=		${WRKDIR}/xc/include/extensions
EXTRACT_AFTER_ARGS= | ${TAR} -xf - xc/include/extensions
NO_BUILD=	yes

do-install:
	${INSTALL} ${WRKSRC}/Print.h ${PREFIX}/include/X11/extensions
	${INSTALL} ${WRKSRC}/Printstr.h ${PREFIX}/include/X11/extensions

.include <bsd.port.mk>
