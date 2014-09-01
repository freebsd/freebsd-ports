# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/pangomm/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	pangomm
PORTVERSION=	2.28.4
PORTREVISION?=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Pango

USES=		tar:xz

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USES+=		gmake libtool pathfix pkgconfig
USE_GNOME=	cairomm glibmm pango
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-documentation \
		--enable-static=yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="2.4" API_VERSION="1.4"

post-patch:
.for d in tests
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/${d}//' \
		${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>

.endif
