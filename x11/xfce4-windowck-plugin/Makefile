PORTNAME=	xfce4-windowck-plugin
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Puts the maximized window title and windows buttons on the panel
WWW=		https://gitlab.xfce.org/panel-plugins/xfce4-windowck-plugin

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
BUILD_DEPENDS=	xdt-csource:devel/xfce4-dev-tools

USES=		gettext-tools gmake gnome libtool python:build pkgconfig \
		shebangfix tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libwnck3 intltool
USE_XFCE=	libmenu panel xfconf
USE_XORG=	x11
SHEBANG_GLOB=	*.py

GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
