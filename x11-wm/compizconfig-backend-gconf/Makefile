# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compizconfig-backend-gconf
PORTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	The gconf backend for CompizConfig

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz
LIB_DEPENDS=	libcompizconfig.so:x11-wm/libcompizconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USES=		libtool:keepla pathfix pkgconfig gmake tar:bzip2
USE_GNOME=	glib20 gconf2

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/settings-backend/gconf.c	\

.include <bsd.port.mk>
