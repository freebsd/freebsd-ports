PORTNAME=	xfce4-whiskermenu-plugin
PORTVERSION=	2.8.2
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Alternate menu for the Xfce Desktop
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-whiskermenu-plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang gettext-tools gnome localbase \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XFCE=	garcon libexo panel xfconf

OPTIONS_DEFINE=		ACCOUNTS_SERVICE GTK_LAYER_SHELL LTO NLS
OPTIONS_DEFAULT=	ACCOUNTS_SERVICE GTK_LAYER_SHELL LTO
OPTIONS_SUB=		yes

ACCOUNTS_SERVICE_DESC=	Enable AccountsService support
GTK_LAYER_SHELL_DESC=	Enable support for positioning in Wayland

ACCOUNTS_SERVICE_LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice
ACCOUNTS_SERVICE_CMAKE_BOOL=	ENABLE_ACCOUNTS_SERVICE

GTK_LAYER_SHELL_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
GTK_LAYER_SHELL_CMAKE_BOOL=	ENABLE_GTK_LAYER_SHELL

LTO_CMAKE_BOOL=	ENABLE_LINK_TIME_OPTIMIZATION

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} '/add_subdirectory(po)/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
