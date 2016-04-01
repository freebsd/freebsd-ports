# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	zenity
PORTVERSION=	3.18.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

LICENSE=	LGPL20

BUILD_DEPENDS=	itstool:textproc/itstool

CONFLICTS=	gtkada-1.2.* zenity-2.*

USES=		gettext gmake gnome pathfix pkgconfig perl5 tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack
USE_XORG=	x11
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=libnotify

post-patch:
	@${RM} ${WRKSRC}/src/gdialog

.include <bsd.port.mk>
