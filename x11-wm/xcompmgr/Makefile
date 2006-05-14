# New ports collection makefile for:   xcompmgr
# Date Created:			16 Oct, 2004
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcompmgr
PORTVERSION=	1.1.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://xapps.freedesktop.org/release/

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	A sample X compositing manager

USE_XLIB=	yes
GNU_CONFIGURE=	yes

MAN1=		xcompmgr.1

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	requires the composite extension, which is unavailable with XFree86
.endif

.include <bsd.port.post.mk>
