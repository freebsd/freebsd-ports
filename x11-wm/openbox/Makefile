# Created by: trevor
# $FreeBSD$

PORTNAME=	openbox
PORTVERSION=	3.6
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://openbox.org/dist/openbox/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Small, fast, standards compliant, extensible window manager

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix python:run pkgconfig shebangfix
USE_GNOME=	cairo glib20 libxml2
USE_XORG=	ice sm x11 xcursor xext xft xinerama xrandr \
		xrender xau
USE_LDCONFIG=	yes
SHEBANG_FILES=	data/autostart/openbox-xdg-autostart

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lXext

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	NLS IMLIB PANGO SVG NOTIFY
OPTIONS_DEFAULT=	IMLIB PANGO NOTIFY SVG
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

PANGO_USE=		GNOME=pango
PANG_CONFIGURE_OFF=	--disable-pango

NOTIFY_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
NOTIFY_CONFIGURE_OFF=	--disable-startup-notification

IMLIB_CONFIGURE_ENABLE=	imlib2
IMLIB_LIB_DEPENDS=	libImlib2.so:graphics/imlib2

SVG_USE=	GNOME=librsvg2
SVG_CONFIGURE_ENABLE=	librsvg

post-configure:
	@${CHMOD} +x ${WRKSRC}/install-sh

.include <bsd.port.mk>
