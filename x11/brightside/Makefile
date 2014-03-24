# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brightside
PORTVERSION=	1.4.0
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	LOCAL/marcus

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Tool to add reactivity to the edges and corners of the GNOME desktop

USES=		gmake pathfix pkgconfig tar:bzip2
USE_XORG=	x11 xt
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix libwnck libgnomeui
CONFIGURE_ARGS=	--enable-tray-icon
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	brightside.schemas

.include <bsd.port.mk>
