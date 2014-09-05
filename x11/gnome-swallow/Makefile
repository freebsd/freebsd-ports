# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-swallow
PORTVERSION=	1.2
PORTREVISION=	11
CATEGORIES=	x11 gnome
MASTER_SITES=	http://interreality.org/~tetron/technology/swallow/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Applet that swallows any X11 application into the GNOME 2 panel

USES=		gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gnomepanel libgnomeui
USE_XORG=	x11
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/GNOME_Swallow.server
	@${REINPLACE_CMD} 's/libpanelapplet-2.0/& libgnomeui-2.0 x11/' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
