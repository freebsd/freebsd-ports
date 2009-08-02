# New ports collection makefile for:	compizconfig-backend-gconf
# Date created:				2007-08-17
# Whom:					Robert Noland <rnoland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	compizconfig-backend-gconf
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	The gconf backend for CompizConfig

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz
LIB_DEPENDS=	compizconfig.0:${PORTSDIR}/x11-wm/libcompizconfig

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22

USE_GNOME=	gnomehack glib20 gconf2

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/settings-backend/gconf.c	\

.include <bsd.port.mk>
