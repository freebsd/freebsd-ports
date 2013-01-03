# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	keyboard
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3696/
DISTNAME=	Keyboard-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop virtual keyboardr

LICENSE=	GPLv3

LIB_DEPENDS=	Desktop:${PORTSDIR}/x11/deforaos-libdesktop

USE_GNOME=	gtk20
USE_PKGCONFIG=	build
USE_XORG=	xtst
USE_GETTEXT=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}

.include <bsd.port.mk>
