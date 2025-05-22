PORTNAME=	xfce4-whiskermenu-plugin
PORTVERSION=	2.10.0
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Alternate menu for the Xfce Desktop
WWW=		https://docs.xfce.org/panel-plugins/xfce4-whiskermenu-plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++14-lang gettext-tools gnome localbase meson \
		pkgconfig tar:xz xfce
USE_GNOME=	gtk30
USE_XFCE=	garcon libexo panel xfconf

OPTIONS_DEFINE=		ACCOUNTS_SERVICE MENULIBRE NLS WAYLAND
OPTIONS_DEFAULT=	ACCOUNTS_SERVICE MENULIBRE WAYLAND
OPTIONS_SUB=		yes

ACCOUNTS_SERVICE_DESC=	Enable AccountsService support
MENULIBRE_DESC=		Depend at runtime on x11/menulibre

ACCOUNTS_SERVICE_LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice
ACCOUNTS_SERVICE_MESON_ENABLED=	accountsservice

MENULIBRE_RUN_DEPENDS=	menulibre:x11/menulibre

NLS_USES=	gettext-runtime

WAYLAND_LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
WAYLAND_MESON_ENABLED=	gtk-layer-shell

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
