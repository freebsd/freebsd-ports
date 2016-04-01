# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	startup-notification
PORTVERSION=	0.12
PORTREVISION=	4
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.freedesktop.org/software/startup-notification/releases/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library that supports startup notification spec from freedesktop.org

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

USE_XORG=	x11
USES=		gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=ac_cv_lib_ICE_IceConnectionNumber=no
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
