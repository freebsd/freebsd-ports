PORTNAME=	cinnamon-session
PORTVERSION=	6.4.2
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the cinnamon desktop
WWW=		https://github.com/linuxmint/cinnamon-session

LICENSE=	GPLv2

LIB_DEPENDS=	libxapp.so:x11/xapp \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libcanberra.so:audio/libcanberra
RUN_DEPENDS=	console-kit-daemon:sysutils/consolekit2 \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR}

USES=		gl gnome meson pkgconfig python:build shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_GLOB=	*.py

USE_GNOME=	cairo gdkpixbuf glib20 gtk30
USE_XORG=	ice sm x11 xau xcomposite xext xrender xtrans xtst
USE_GL=		gl

GLIB_SCHEMAS=	org.cinnamon.SessionManager.gschema.xml

OPTIONS_DEFINE=	IPV6
OPTIONS_DEFAULT=	IPV6

IPV6_MESON_TRUE=	ipv6

.include <bsd.port.mk>
