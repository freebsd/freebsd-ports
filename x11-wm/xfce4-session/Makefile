PORTNAME=	xfce4-session
PORTVERSION=	4.20.0
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's session manager
WWW=		https://gitlab.xfce.org/xfce/xfce4-session

LICENSE=	GPLv2

BUILD_DEPENDS=	iceauth:x11/iceauth
RUN_DEPENDS=	iceauth:x11/iceauth \
		console-kit-daemon:sysutils/consolekit2 \
		xrdb:x11/xrdb
LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix \
		pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 glib20 libwnck3
USE_XFCE=	libmenu xfconf windowing
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-legacy-sm \
		--with-backend=freebsd \
		--enable-x11 \
		--enable-polkit \
		--with-xsession-prefix=${PREFIX} \
		--with-wayland-session-prefix=${PREFIX}
SUB_FILES=	pkg-message
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NLS WAYLAND
OPTIONS_DEFAULT=	WAYLAND
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

WAYLAND_LIB_DEPENDS=		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell \
				libwayland-client.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=	gtk-layer-shell wayland

.include <bsd.port.mk>
