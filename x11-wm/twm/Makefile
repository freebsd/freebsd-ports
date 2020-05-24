# $FreeBSD$

PORTNAME=	twm
PORTVERSION=	1.0.10
PORTREVISION=	1
CATEGORIES=	x11-wm

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/app/${PORTNAME}/-/commit/
PATCHFILES+=	e2a533d16e04.diff:-p1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Tab Window Manager for the X Window System

USES=		xorg xorg-cat:app
USE_XORG=	ice sm x11 xext xt xmu

.include <bsd.port.mk>
