PORTNAME=	xfce4-windowck-plugin
PORTVERSION=	0.6.1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Puts the maximized window title and windows buttons on the panel
WWW=		https://gitlab.xfce.org/panel-plugins/xfce4-windowck-plugin

LICENSE=	GPLv2

USES=		gettext-tools gnome meson pkgconfig python:build shebangfix \
		tar:xz xfce xorg
USE_GNOME=	glib20 gtk30 libwnck3
USE_XFCE=	libmenu panel xdt xfconf
USE_XORG=	x11
SHEBANG_GLOB=	*.py
BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
