# $FreeBSD$

PORTNAME=	libinput
PORTVERSION=	1.15.4
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic input library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}evdev>0:devel/py-evdev@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyudev>0:devel/py-pyudev@${PY_FLAVOR}
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libepoll-shim.so:devel/libepoll-shim \
		libudev.so:devel/libudev-devd \
		libmtdev.so:devel/libmtdev

USES=		localbase meson pkgconfig python:3.4+,run shebangfix tar:xz
USE_LDCONFIG=	yes

MESON_ARGS+=	-Ddocumentation=false -Dtests=false

python_OLD_CMD=	"/usr/bin/env python3"
SHEBANG_FILES=	tools/libinput-measure-fuzz.py \
		tools/libinput-measure-touch-size.py \
		tools/libinput-measure-touchpad-pressure.py \
		tools/libinput-measure-touchpad-tap.py \
		tools/libinput-replay

OPTIONS_DEFINE=	DEBUG_GUI LIBWACOM
OPTIONS_DEFAULT=LIBWACOM
OPTIONS_SUB=	yes

DEBUG_GUI_DESC=	Build the GUI event viewer
LIBWACOM_DESC=	Libwacom support

DEBUG_GUI_USES=		gnome
DEBUG_GUI_USE=		GNOME=gtk30,glib20,cairo
DEBUG_GUI_MESON_TRUE=	debug-gui
LIBWACOM_LIB_DEPENDS=	libwacom.so:x11/libwacom
LIBWACOM_MESON_TRUE=	libwacom

.include <bsd.port.mk>
