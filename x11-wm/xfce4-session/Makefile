PORTNAME=	xfce4-session
PORTVERSION=	4.20.3
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's session manager
WWW=		https://gitlab.xfce.org/xfce/xfce4-session

LICENSE=	GPLv2

BUILD_DEPENDS=	iceauth:x11/iceauth
LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit
RUN_DEPENDS=	console-kit-daemon:sysutils/consolekit2 \
		iceauth:x11/iceauth \
		xrdb:x11/xrdb

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix \
		pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libwnck3
USE_XFCE=	libmenu windowing xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-legacy-sm \
		--enable-polkit \
		--enable-x11 \
		--with-backend=freebsd \
		--with-wayland-session-prefix=${PREFIX} \
		--with-xsession-prefix=${PREFIX}
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		NLS WAYLAND
OPTIONS_DEFAULT=	WAYLAND
OPTIONS_SUB=		yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

WAYLAND_LIB_DEPENDS=		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
WAYLAND_CONFIGURE_ENABLE=	gtk-layer-shell wayland

.include <bsd.port.mk>
