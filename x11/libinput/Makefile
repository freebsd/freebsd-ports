PORTNAME=	libinput
DISTVERSION=	1.31.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic input library
WWW=		https://www.freedesktop.org/wiki/Software/libinput/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libevdev.so:devel/libevdev \
		libmtdev.so:devel/libmtdev \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libevdev>0:devel/py-libevdev@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyudev>0:devel/py-pyudev@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		bash:shells/bash

USES=		cpe localbase lua meson pkgconfig python:run,test shebangfix
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org

CPE_VENDOR=	freedesktop

MESON_ARGS=	-Ddocumentation=false

SHEBANG_FILES=	test/*.py \
		test/*.sh \
		test/symbols-leak-test \
		tools/*.py

OPTIONS_DEFINE=		DEBUG_GUI LIBWACOM TEST
OPTIONS_DEFAULT=	LIBWACOM
OPTIONS_SUB=		yes

DEBUG_GUI_DESC=		Build the GUI event viewer
LIBWACOM_DESC=		Libwacom support

DEBUG_GUI_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
DEBUG_GUI_USES=		gnome xorg
DEBUG_GUI_USE=		GNOME=cairo,glib20,gtk30 \
			XORG=x11
DEBUG_GUI_MESON_TRUE=	debug-gui

LIBWACOM_LIB_DEPENDS=	libwacom.so:x11/libwacom
LIBWACOM_MESON_TRUE=	libwacom
# If built with WITH_DEBUG=yes running tests require /dev/input/* devices
# In case of poudriere jail run following commands on host:
# devfs -m /usr/local/poudriere/data/.m/<jail>-<ports>/ref/dev rule apply path 'input' unhide
# devfs -m /usr/local/poudriere/data/.m/<jail>-<ports>/ref/dev rule apply path 'input/*' unhide
TEST_LIB_DEPENDS=	libcheck.so:devel/check
TEST_MESON_TRUE=	tests

post-patch:
	${REINPLACE_CMD} -e 's|sed|sed -E|g' ${WRKSRC}/test/symbols-leak-test

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/udev

.include <bsd.port.mk>
