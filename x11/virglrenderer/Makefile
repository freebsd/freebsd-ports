PORTNAME=	virglrenderer
DISTVERSION=	1.2.0
CATEGORIES=	x11

MAINTAINER=	monwarez@mailoo.org
COMMENT=	VirGL virtual OpenGL renderer
WWW=		https://virgil3d.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy

USES=		cmake:indirect compiler:c++11-lang cpe gl meson pkgconfig \
		python xorg
CPE_VENDOR=	${PORTNAME}_project
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	virgl
USE_GL=		gbm
USE_XORG=	x11

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		VENUS
OPTIONS_DEFAULT=	VENUS
OPTIONS_SUB=		yes

VENUS_DESC=		Support for vulkan
VENUS_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
VENUS_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
			libepoll-shim.so:devel/libepoll-shim
VENUS_MESON_TRUE=	venus

.include <bsd.port.mk>
