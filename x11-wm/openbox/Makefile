# Created by: trevor
# $FreeBSD$

PORTNAME=	openbox
PORTVERSION=	3.5.2
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://openbox.org/dist/openbox/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Small, fast, standards compliant, extensible window manager

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		libtool gmake pathfix pkgconfig
USE_GNOME=	glib20 libxml2
USE_XORG=	xft
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=${PORTVERSION:C/.[0-9]+\$//}

OPTIONS_DEFINE=	NLS IMLIB PANGO NOTIFY
OPTIONS_DEFAULT=	IMLIB PANGO NOTIFY
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

PANGO_USE=		GNOME=pango
PANG_CONFIGURE_OFF=	--disable-pango

NOTIFY_LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
NOTIFY_CONFIGURE_OFF=	--disable-startup-notification

IMLIB_CONFIGURE_ENABLE=	imlib2
IMLIB_USE=	EFL=imlib2

post-configure:
	@${CHMOD} +x ${WRKSRC}/install-sh

.include <bsd.port.mk>
