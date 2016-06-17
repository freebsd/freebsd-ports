# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	xfce4-session
PORTVERSION=	4.12.1
PORTREVISION=	3
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE/src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's session manager

LICENSE=	GPLv2

BUILD_DEPENDS=	iceauth:x11/iceauth
RUN_DEPENDS=	iceauth:x11/iceauth \
		console-kit-daemon:sysutils/consolekit
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libupower-glib.so:sysutils/upower \
		libpolkit-gobject-1.so:sysutils/polkit

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gtk20 glib20 intltool intlhack libwnck
USES=		pathfix pkgconfig gmake libtool gettext-tools xfce tar:bzip2
USE_LDCONFIG=	yes
USE_XFCE=	libmenu
USE_XORG=	x11 sm ice

CONFIGURE_ARGS+=--enable-legacy-sm \
		--with-xsession-prefix=${PREFIX}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

PLIST_SUB=	VERSION="4.6"

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/scripts/xflock4

.include <bsd.port.mk>
