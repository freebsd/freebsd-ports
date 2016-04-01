# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	menu-cache
PORTVERSION=	1.0.1
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Library used to read freedesktop.org menus

LICENSE=	LGPL21

LIB_DEPENDS=	libfm-extra.so:x11/libfm-extra

USES=		gmake pathfix pkgconfig libtool tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=--disable-static

.include <bsd.port.mk>
