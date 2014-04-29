# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/gnome-terminal/Makefile,v 1.137 2010/11/13 13:25:22 kwm Exp $

PORTNAME=	gnome-terminal
PORTVERSION=	2.32.1
PORTREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 2 Desktop

LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
INSTALLS_OMF=	yes
USE_XORG=	ice sm
USE_GNOME=	gnomeprefix intlhack gconf2 vte gnomedocutils libgnome
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnome-terminal.schemas

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} '/SMCLIENT_LIBS =/s/$$/ -lICE/' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
