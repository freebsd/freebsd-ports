# New ports collection makefile for:	compizconfig-backend-gconf
# Date created:				2007-08-17
# Whom:					Robert Noland <rnoland@2hip.net>
#
# $FreeBSD$
#

PORTNAME=	compizconfig-backend-gconf
PORTVERSION=	0.5.2
#PORTREVISION=	0
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz-fusion.org/${PORTVERSION}/

MAINTAINER=	rnoland@2hip.net
COMMENT=	The gconf backend for CompizConfig

BUILD_DEPENDS=	\
	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz \
	${LOCALBASE}/libdata/pkgconfig/libcompizconfig.pc:${PORTSDIR}/x11-wm/libcompizconfig

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15

USE_GNOME=	gnomehack glib20 gconf2

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/settings-backend/gconf.c	\

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
