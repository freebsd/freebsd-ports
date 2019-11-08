# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	menu-cache
PORTVERSION=	1.1.0
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Library used to read freedesktop.org menus

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfm-extra.so:x11/libfm-extra

USES=		gettext-runtime gmake gnome libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-static

.include <bsd.port.mk>
