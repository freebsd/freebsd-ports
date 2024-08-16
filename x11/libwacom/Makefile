PORTNAME=	libwacom
DISTVERSION=	2.12.2
CATEGORIES=	x11
MASTER_SITES=	https://github.com/linuxwacom/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Adds tablet support to libinput
WWW=		https://github.com/linuxwacom/libwacom/wiki

LICENSE=	HPND
LICENSE_NAME=	Historical Permission Notice and Disclaimer
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		${PYTHON_PKGNAMEPREFIX}libevdev>0:devel/py-libevdev \
		${PYTHON_PKGNAMEPREFIX}pyudev>0:devel/py-pyudev \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libgudev-1.0.so:devel/libgudev
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libevdev>0:devel/py-libevdev
TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gnome meson pkgconfig python shebangfix \
		tar:xz

USE_GNOME=	glib20
USE_LDCONFIG=	yes

SHEBANG_FILES=	tools/show-stylus.py tools/libwacom-update-db.py

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/tools/libwacom-update-db.py

.include <bsd.port.mk>
