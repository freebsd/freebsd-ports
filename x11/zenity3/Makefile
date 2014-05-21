# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/zenity3/Makefile 19671 2014-05-17 18:45:02Z gusi $

PORTNAME=	zenity
PORTVERSION=	3.12.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

LICENSE=	LGPL20

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

CONFLICTS=	gtkada-1.2.* zenity-2.*

USES=		gettext gmake pathfix pkgconfig perl5 tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack
USE_XORG=	x11
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY
NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
NOTIFY_CONFIGURE_ENABLE=libnotify

.include <bsd.port.mk>
