PORTNAME=	mate-dock-applet
PORTVERSION=	21.10.0
PORTREVISION=	4
CATEGORIES=	x11 mate
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Application dock applet for the MATE panel
WWW=		https://github.com/ubuntu-mate/mate-dock-applet

LICENSE=	GPLv3
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbamf3.so:sysutils/bamf

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xlib>=0:x11-toolkits/py-python-xlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg@${PY_FLAVOR}

USES=		python autoreconf gettext gmake gnome libtool localbase \
		pkgconfig shebangfix tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	ubuntu-mate
USE_GNOME=	gtk30 libwnck3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk3
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	src/*.in

GLIB_SCHEMAS=	org.mate.panel.applet.dock.gschema.xml

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/env python3|${PYTHON_CMD}|g' \
		${WRKSRC}/src/org.mate.panel.applet.DockAppletFactory.service.in

.include <bsd.port.mk>
