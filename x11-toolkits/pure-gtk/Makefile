# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-gtk
PORTVERSION=	0.11
CATEGORIES=	x11-toolkits

MAINTAINER=	lichray@gmail.com
COMMENT=	A set of Pure language bindings for GTK+

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USES=		pkgconfig
USE_PURE=	ffi
USE_GNOME=	glib20 gtk20 atk pango

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/pure/bsd.pure.mk"
.include <bsd.port.mk>
