# New ports collection makefile for:   PrintExt
# Date Created:			4 May 2004
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	printext
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/X11R6.7.0/src/ \
		${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R6.7/tars
DISTNAME=	X11R6.7.0-src1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Header files for the X Print Extension

CONFLICTS=	XFree86-libraries-* xorg-libraries-*

PREFIX?=	${X11BASE}
DIST_SUBDIR=	xorg
WRKSRC=		${WRKDIR}/xc/include/extensions
EXTRACT_AFTER_ARGS= | ${TAR} -xf - xc/include/extensions
NO_BUILD=	yes

DEST=${PREFIX}/include/X11/extensions

do-install:
	${MKDIR} ${DEST}
	${INSTALL_DATA} ${WRKSRC}/Print.h ${DEST}
	${INSTALL_DATA} ${WRKSRC}/Printstr.h ${DEST}

.include <bsd.port.mk>
