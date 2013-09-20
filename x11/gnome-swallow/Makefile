# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-swallow
PORTVERSION=	1.2
PORTREVISION=	11
CATEGORIES=	x11 gnome
MASTER_SITES=	http://interreality.org/~tetron/technology/swallow/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Applet that swallows any X11 application into the GNOME 2 panel

USE_XORG=	x11
USES=		gmake pkgconfig
USE_GNOME=	gnomeprefix gnomehack gnomepanel libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="`pkg-config --libs libgnomeui-2.0`"
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/GNOME_Swallow.server

.include <bsd.port.mk>
