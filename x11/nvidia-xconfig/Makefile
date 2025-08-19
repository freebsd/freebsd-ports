PORTNAME=	nvidia-xconfig
PORTVERSION=	580.76.05
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Tool to manipulate X configuration files for the NVidia driver
WWW=		https://www.nvidia.com/object/unix.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	NVIDIA

MAKE_ENV=	NV_VERBOSE=1

PLIST_FILES=	bin/nvidia-xconfig \
		share/man/man1/nvidia-xconfig.1.gz

.include <bsd.port.mk>
