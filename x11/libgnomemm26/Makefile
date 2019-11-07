# Created by: Alexander Nedotsukov <bland@mail.ru>
# $FreeBSD$
#   $MCom: ports/x11/libgnomemm26/Makefile,v 1.24 2010/03/30 13:34:10 avl Exp $

PORTNAME=	libgnomemm
PORTVERSION=	2.30.0
PORTREVISION=	10
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgnome library

LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24

USES=		compiler:c++11-lang gmake gnome libtool:keepla pathfix \
		pkgconfig tar:bzip2 xorg
USE_CXXSTD=	c++11
USE_XORG=	xext
USE_GNOME=	libgnome
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static
INSTALL_TARGET=	install-strip
BINARY_WRAPPERS=	gm4

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

.include <bsd.port.mk>
