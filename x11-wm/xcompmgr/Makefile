# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xcompmgr
PORTVERSION=	1.1.6
CATEGORIES=	x11-wm

MAINTAINER=	x11@FreeBSD.org
COMMENT=	A sample X compositing manager

XORG_CAT=	app
USE_XORG=	x11 xcomposite xfixes xdamage xrender

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xorg-macros.pc:${PORTSDIR}/devel/xorg-macros

PLIST_FILES=	bin/${PORTNAME}

MAN1=		xcompmgr.1

.include <bsd.port.mk>
