PORTNAME=	xfce4-desktop
PORTVERSION=	4.20.0
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE
DISTNAME=	xfdesktop-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's desktop manager
WWW=		https://gitlab.xfce.org/xfce/xfdesktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libnotify.so:devel/libnotify \
		libyaml.so:textproc/libyaml

USES=		compiler:c11 gettext-tools gmake gnome pkgconfig tar:bzip2 xfce \
		xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libwnck3
USE_XFCE=	garcon libexo windowing xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gio-unix \
		--enable-notifications
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NLS THUNAR WAYLAND
OPTIONS_DEFAULT=	THUNAR WAYLAND
OPTIONS_SUB=		yes

THUNAR_DESC=		Thunar file manager support

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

THUNAR_USE=			XFCE=thunar
THUNAR_CONFIGURE_ENABLE=	thunarx
THUNAR_CONFIGURE_WITH=		file-manager-fallback=Thunar

WAYLAND_LIB_DEPENDS=		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
WAYLAND_CONFIGURE_ENABLE=	wayland

.include <bsd.port.mk>
