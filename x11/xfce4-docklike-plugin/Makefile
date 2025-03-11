PORTNAME=	xfce4-docklike-plugin
PORTVERSION=	0.4.3
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	bsd@quentb.com
COMMENT=	Modern, minimalist taskbar for Xfce
WWW=		https://gitlab.xfce.org/panel-plugins/xfce4-docklike-plugin

LICENSE=	GPLv3

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		gettext-tools gmake gnome libtool pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf gtk30
USE_XFCE=	libmenu panel windowing
USE_XORG=	x11

GNU_CONFIGURE=		yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
