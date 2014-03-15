# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compizconfig-backend-gconf
PORTVERSION=	0.8.4
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The gconf backend for CompizConfig

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz
LIB_DEPENDS=	compizconfig.0:${PORTSDIR}/x11-wm/libcompizconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

USES=		pathfix pkgconfig gmake tar:bzip2
USE_GNOME=	glib20 gconf2

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/settings-backend/gconf.c	\

.include <bsd.port.mk>
