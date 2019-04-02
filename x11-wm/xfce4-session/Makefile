# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	xfce4-session
PORTVERSION=	4.12.1
PORTREVISION=	6
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE/src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's session manager

LICENSE=	GPLv2

BUILD_DEPENDS=	iceauth:x11/iceauth
RUN_DEPENDS=	iceauth:x11/iceauth \
		console-kit-daemon:sysutils/consolekit2
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus \
		libupower-glib.so:sysutils/upower \
		libpolkit-gobject-1.so:sysutils/polkit \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-tools gmake gnome libtool pathfix pkgconfig \
		tar:bzip2 xfce
USE_GNOME=	cairo gtk20 glib20 intlhack intltool libwnck
USE_LDCONFIG=	yes
USE_XFCE=	libmenu
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-legacy-sm \
		--with-xsession-prefix=${PREFIX}
SUB_FILES=	pkg-message
PLIST_SUB=	VERSION="4.6"
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/scripts/xflock4

.include <bsd.port.mk>
