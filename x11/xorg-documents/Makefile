# New ports collection makefile for:    xorg-documents
# Date created:		23 July 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-documents
PORTVERSION=	6.7.0
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/~xorg/X11R6.7.0/src/
DISTFILES=	X11R6.7.0-src1.tar.gz \
		X11R6.7.0-src6.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Documentation of X11 protocol and libraries from X.Org

EXTRA_PATCHES=	${CF_PATCHES}

XBUILD_DIRS=	doc/specs

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	is part of X.Org
.endif

.include <bsd.port.post.mk>
