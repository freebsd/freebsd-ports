# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pangomm
PORTVERSION=	2.40.1
PORTREVISION?=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Pango

LICENSE=	LGPL21

USES=		tar:xz

.if !defined(REFERENCE_PORT)
PORTSCOUT=	limitw:1,even

USES+=		gmake libtool localbase pathfix pkgconfig compiler:c++11-lang
USE_CXXSTD=	c++11
USE_GNOME=	cairomm glibmm pango
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation \
		--enable-static=yes
INSTALL_TARGET=	install-strip
BINARY_WRAPPERS=	gm4

PLIST_SUB=	VERSION="2.4" API_VERSION="1.4"

post-patch:
.for d in tests
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/${d}//' \
		${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>

.else
PORTSCOUT=	ignore:1
.endif
