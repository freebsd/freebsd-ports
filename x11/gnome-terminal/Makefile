# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-terminal3/Makefile 18559 2013-06-17 20:56:34Z kwm $

PORTNAME=	gnome-terminal
PORTVERSION=	3.6.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 3 Desktop

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
INSTALLS_OMF=	yes
USE_XORG=	sm ice
USE_GNOME=	gconf2 gnomeprefix intlhack vte3 gnomedocutils
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnome-terminal.schemas

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.mk>
