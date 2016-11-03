# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	qt-x11
PORTVERSION=	4.8.5
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux
SRC_DISTFILES=	qt-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-qt47-x11-[0-9]*

RPMVERSION=	11.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	alsalib dri fontconfig jpeg openssl png qt tiff xorglibs
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../../devel/qt4/pkg-descr

.include <bsd.port.mk>
