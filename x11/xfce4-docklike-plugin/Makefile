PORTNAME=		xfce4-docklike-plugin
PORTVERSION=		0.4.0
DISTVERSIONPREFIX=	${PORTNAME}
PORTREVISION=	1
CATEGORIES=		x11 xfce

MAINTAINER=		bsd@quentb.com
COMMENT=		Modern, minimalist taskbar for Xfce
WWW=		https://gitlab.xfce.org/panel-plugins/xfce4-docklike-plugin

LICENSE=		GPLv3

BUILD_DEPENDS=		xdt-csource:devel/xfce4-dev-tools
LIB_DEPENDS=		libinotify.so:devel/libinotify \
			libharfbuzz.so:print/harfbuzz

USES=			gettext-tools gmake gnome libtool pkgconfig xfce \
			xorg

USE_GITLAB=		yes
GL_SITE=		https://gitlab.xfce.org
GL_ACCOUNT=		panel-plugins
GL_TAGNAME=		e6831250e5ca792f31ef4b493b1a92020fe1ab6b

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	autogen.sh
INSTALL_TARGET=		install-strip
LDFLAGS+=		-L${LOCALBASE}/lib -linotify

USE_GNOME=		cairo gdkpixbuf2 gtk30 intltool libwnck3
USE_XFCE=		panel
USE_XORG=		x11

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes
NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
