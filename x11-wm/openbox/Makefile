# Created by: trevor
# $FreeBSD$

PORTNAME=	openbox
PORTVERSION=	3.5.2
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://openbox.org/dist/openbox/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Small, fast, standards compliant, extensible window manager

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	glib20 libxml2 gnomehack ltverhack
USE_XORG=	xft
USE_AUTOTOOLS=	libtool
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMLIB}
USE_EFL=	imlib2
.else
CONFIGURE_ARGS+=	--disable-imlib2
.endif

post-configure:
	@${CHMOD} +x ${WRKSRC}/install-sh

.include <bsd.port.mk>
