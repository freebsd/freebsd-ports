# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	qt-x11
PORTVERSION=	4.8.5
CATEGORIES=	x11-toolkits linux
SRC_DISTFILES=	qt-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-qt47-x11-[0-9]*

RPMVERSION=	11.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig png xorglibs alsalib jpeg tiff qt openssl
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	NVIDIA_GL

NVIDIA_GL_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver
NVIDIA_GL_USE=		LINUX=libglu
NVIDIA_GL_USE_OFF=	LINUX=dri

DESCR=		${.CURDIR}/../../devel/qt4/pkg-descr

.include <bsd.port.mk>
