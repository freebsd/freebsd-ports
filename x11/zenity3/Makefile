# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/zenity3/Makefile 18972 2014-01-16 21:18:10Z kwm $

PORTNAME=	zenity
PORTVERSION=	3.6.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

LICENSE=	LGPL20

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

CONFLICTS=	gtkada-1.2.* zenity-2.*

USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gtk30 intlhack
USE_XORG=	x11
USE_XZ=		yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=		libnotify.so:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=	--enable-libnotify
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif

.include <bsd.port.mk>
