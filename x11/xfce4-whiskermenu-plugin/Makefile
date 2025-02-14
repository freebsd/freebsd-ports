PORTNAME=	xfce4-whiskermenu-plugin
PORTVERSION=	2.9.1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Alternate menu for the Xfce Desktop
WWW=		https://docs.xfce.org/panel-plugins/xfce4-whiskermenu-plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang gettext-tools gnome localbase \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XFCE=	garcon libexo panel xfconf

OPTIONS_DEFINE=		ACCOUNTS_SERVICE LTO MENULIBRE NLS WAYLAND
OPTIONS_DEFAULT=	ACCOUNTS_SERVICE LTO MENULIBRE WAYLAND
OPTIONS_SUB=		yes

ACCOUNTS_SERVICE_DESC=	Enable AccountsService support
MENULIBRE_DESC=		Depend at runtime on x11/menulibre

ACCOUNTS_SERVICE_LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice
ACCOUNTS_SERVICE_CMAKE_BOOL=	ENABLE_ACCOUNTS_SERVICE

LTO_CMAKE_BOOL=	ENABLE_LINK_TIME_OPTIMIZATION

MENULIBRE_RUN_DEPENDS=	menulibre:x11/menulibre

NLS_USES=	gettext-runtime

WAYLAND_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
WAYLAND_CMAKE_BOOL=	ENABLE_GTK_LAYER_SHELL

post-patch-NLS-off:
	@${REINPLACE_CMD} '/add_subdirectory(po)/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
