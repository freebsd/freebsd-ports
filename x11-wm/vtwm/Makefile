# New ports collection makefile for:	vtwm
# Date created:		21 December 1998
# Whom:			bmah@ca.sandia.gov
#
# $FreeBSD$
#

PORTNAME=	vtwm
PORTVERSION=	5.4.6b
PORTREVISION=	0
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.visi.com/users/hawkeyd/X/

MAINTAINER=	ports@freebsd.org
COMMENT=	Twm with a virtual desktop and optional Motif-like features

USE_IMAKE=	yes
USE_XPM=	yes

MAN1=		vtwm.1

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xorg
PLIST_SUB+=	NEWMTREE=""
.else
PLIST_SUB+=	NEWMTREE="@comment "
.endif

.include <bsd.port.post.mk>
