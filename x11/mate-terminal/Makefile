# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-terminal
PORTVERSION=	1.8.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the MATE Desktop

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_XORG=	sm x11
USE_GNOME=	dconf gnomehier gtk20 intlhack vte
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.terminal.gschema.xml

.include <bsd.port.mk>
