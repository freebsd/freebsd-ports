PORTNAME=	libinput
DISTVERSION=	1.19.4
PORTREVISION=	1
CATEGORIES=	x11 wayland
MASTER_SITES=	https://freedesktop.org/software/${PORTNAME}/

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

USES=		cpe localbase meson pkgconfig python:run shebangfix tar:xz
USE_LDCONFIG=	yes

CPE_VENDOR=	freedesktop

MESON_ARGS=	-Ddocumentation=false -Dtests=false

SHEBANG_FILES=	tools/libinput-analyze-per-slot-delta.py \
		tools/libinput-analyze-recording.py \
		tools/libinput-analyze-touch-down-state.py \
		tools/libinput-measure-fuzz.py \
		tools/libinput-measure-touch-size.py \
		tools/libinput-measure-touchpad-pressure.py \
		tools/libinput-measure-touchpad-size.py \
		tools/libinput-measure-touchpad-tap.py \
		tools/libinput-replay.py
# The following files are not installed, but might be
# run as part of the test suite.
SHEBANG_FILES+=	tools/test_tool_option_parsing.py \
		tools/libinput-record-verify-yaml.py

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
