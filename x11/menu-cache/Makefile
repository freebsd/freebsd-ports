# New ports collection makefile for:	x11-fm/menu-cache
# Date created:				23 Sept 2010
# Whom:					Kris Moore <kmoore@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	menu-cache
PORTVERSION=	0.3.2
CATEGORIES=	x11-fm
MASTER_SITES=	SF/lxde/menu-cache/menu-cache%20${PORTVERSION}/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	The menu-cache portion of LXDE

USE_GNOME=	gtk20 pkgconfig
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_FAM=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

post-configure:
	${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/libmenu-cache/Makefile.in
	${REINPLACE_CMD} -e 's|(datadir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/libmenu-cache/Makefile.in
	${REINPLACE_CMD} -e 's|(prefix)/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/libmenu-cache/Makefile.in

.include <bsd.port.post.mk>
