PORTNAME=		xfce4-docklike-plugin
PORTVERSION=		0.4.1
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	1
CATEGORIES=		x11 xfce

MAINTAINER=		bsd@quentb.com
COMMENT=		Modern, minimalist taskbar for Xfce
WWW=			https://gitlab.xfce.org/panel-plugins/xfce4-docklike-plugin

LICENSE=		GPLv3

BUILD_DEPENDS=		xdt-csource:devel/xfce4-dev-tools
LIB_DEPENDS=		libharfbuzz.so:print/harfbuzz

USES=			gettext-tools gmake gnome libtool pkgconfig xfce \
			xorg

USE_GITLAB=		yes
GL_SITE=		https://gitlab.xfce.org
GL_ACCOUNT=		panel-plugins

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	autogen.sh
INSTALL_TARGET=		install-strip

USE_GNOME=		cairo gdkpixbuf2 gtk30 intltool libwnck3
USE_XFCE=		libmenu panel
USE_XORG=		x11

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
