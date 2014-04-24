# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	menu-cache
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/menu-cache/menu-cache%20$${PORTVERSION:R}.x/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	The menu-cache portion of LXDE

USES=		fam gmake pathfix pkgconfig
USE_GNOME=	glib20
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmenu-cache.so.3

.include <bsd.port.mk>
