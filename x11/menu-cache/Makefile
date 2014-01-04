# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	menu-cache
PORTVERSION=	0.5.1
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/menu-cache/menu-cache%20$${PORTVERSION:R}.x/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	The menu-cache portion of LXDE

USES=		fam gmake pkgconfig
USE_GNOME=	gnomehack glib20
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
