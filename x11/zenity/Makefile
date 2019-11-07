# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	zenity
PORTVERSION=	3.28.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display GNOME dialogs from the command line

LICENSE=	LGPL20

BUILD_DEPENDS=	itstool:textproc/itstool

CONFLICTS=	gtkada-1.2.* zenity-2.*

USES=		gettext gmake gnome localbase pathfix pkgconfig \
		perl5 tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gnomeprefix gtk30 intlhack
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-webkitgtk

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=libnotify

post-patch:
	@${RM} ${WRKSRC}/src/gdialog

.include <bsd.port.mk>
