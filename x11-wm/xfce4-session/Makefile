# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	xfce4-session
PORTVERSION=	4.14.0
PORTREVISION=	1
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's session manager

LICENSE=	GPLv2

BUILD_DEPENDS=	iceauth:x11/iceauth
RUN_DEPENDS=	iceauth:x11/iceauth \
		console-kit-daemon:sysutils/consolekit2
LIB_DEPENDS=	libupower-glib.so:sysutils/upower \
		libpolkit-gobject-1.so:sysutils/polkit

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix \
		pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gtk30 glib20 intltool libwnck3
USE_XFCE=	libexo xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-legacy-sm \
		--with-xsession-prefix=${PREFIX}
SUB_FILES=	pkg-message
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
