PORTNAME=	virglrenderer
DISTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	VirGL virtual OpenGL renderer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_riscv64=		fails to build: ../src/gallium/include/pipe/p_config.h:171:2: Unknown Endianness

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy

USES=		compiler:c++11-lang gl meson pkgconfig python:3.5+
USE_GITLAB=	yes
USE_GL=		gbm
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	virgl
GL_COMMIT=	7d204f3927be65fb3365dce01dbcd04d447a4985

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
