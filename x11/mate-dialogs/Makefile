# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	mate-dialogs
PORTVERSION=	1.8.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display MATE dialogs from the command line

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomehier gtk20 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-I${LOCALBASE}/lib

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.include <bsd.port.mk>
