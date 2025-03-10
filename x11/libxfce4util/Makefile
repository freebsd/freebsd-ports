PORTNAME=	libxfce4util
PORTVERSION=	4.20.0
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Extension library for the Xfce desktop environment
WWW=		https://gitlab.xfce.org/xfce/libxfce4util

LICENSE=	GPLv2

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig tar:bzip2 xfce
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_XFCE=	xdt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-html-dir
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		GIR NLS VAPI
OPTIONS_DEFAULT=	GIR VAPI
OPTIONS_SUB=		yes

GIR_DESC=		Use Gobject Introspection

GIR_USE=		GNOME=introspection:build
GIR_CONFIGURE_ON=	--enable-introspection=yes
GIR_CONFIGURE_OFF=	--enable-introspection=no

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
#NLS_CONFIGURE_ENV=	LIBS=-lintl LDFLAGS=-L${LOCALBASE}/lib

VAPI_IMPLIES=		GIR
VAPI_USES=		vala:build
VAPI_CONFIGURE_ENABLE=	vala

.include <bsd.port.mk>
