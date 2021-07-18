PORTNAME=	pangolin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight rapid development library for managing OpenGL display

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		liblz4.so:archivers/liblz4 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++14-lang gl jpeg pkgconfig
USE_GL=		gl glew glu
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	stevenlovegrove
GH_PROJECT=	Pangolin

LDFLAGS+=	-pthread

.include <bsd.port.mk>
