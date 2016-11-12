# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	menu-cache
PORTVERSION=	1.0.2
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Library used to read freedesktop.org menus

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfm-extra.so:x11/libfm-extra

USES=		gmake gettext-runtime libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=--disable-static

.include <bsd.port.mk>
