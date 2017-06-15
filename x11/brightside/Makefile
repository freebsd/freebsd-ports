# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brightside
PORTVERSION=	1.4.0
PORTREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	LOCAL/marcus

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Tool to add reactivity to the edges and corners of the GNOME desktop

USES=		gmake pathfix pkgconfig tar:bzip2
USE_XORG=	x11
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix libwnck libgnomeui intltool
CONFIGURE_ARGS=	--enable-tray-icon
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

GCONF_SCHEMAS=	brightside.schemas

.include <bsd.port.mk>
