PORTNAME=	cinnamon-session
DISTVERSION=	6.4.0
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the cinnamon desktop
WWW=		https://github.com/linuxmint/cinnamon-session

LICENSE=	GPLv2

LIB_DEPENDS=	libcinnamon-desktop.so:x11/cinnamon-desktop \
		libxapp.so:x11/xapp \
		libcanberra.so:audio/libcanberra
RUN_DEPENDS=	console-kit-daemon:sysutils/consolekit2 \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR}

USES=		gl gnome meson pkgconfig shebangfix xorg python:build

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_FILES=	data/meson_install_schemas.py \
		cinnamon-session-quit/cinnamon-session-quit.py

USE_GNOME=	cairo gdkpixbuf glib20 gtk30 pango
USE_XORG=	ice sm x11 xau xcomposite xext xrender xtrans xtst
USE_GL=		gl
GLIB_SCHEMAS=	org.cinnamon.SessionManager.gschema.xml

MESON_ARGS=	-Dxtrans=true

OPTIONS_DEFINE=		IPV6
OPTIONS_DEFAULT=	IPV6

IPV6_MESON_TRUE=	ipv6

.include <bsd.port.mk>
