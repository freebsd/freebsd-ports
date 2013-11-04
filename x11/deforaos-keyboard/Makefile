# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	keyboard
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3696/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Keyboard-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop virtual keyboardr

LICENSE=	GPLv3

LIB_DEPENDS=	libDesktop.so:${PORTSDIR}/x11/deforaos-libdesktop

USE_GNOME=	gtk20
USES=		desktop-file-utils gettext pkgconfig
USE_XORG=	xtst
MAKE_ARGS+=	PREFIX=${PREFIX}

.include <bsd.port.mk>
