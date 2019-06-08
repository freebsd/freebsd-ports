# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	qt47-x11
PORTVERSION=	4.7.2
DISTVERSIONSUFFIX=	-1_18.el6
PORTREVISION=	6
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	LOCAL/tijl/atrpms:amd64,i386
DIST_SUBDIR=	atrpms

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform application and UI framework (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	alsalib dri fontconfig jpeg openssl png qt tiff xorglibs
USE_LINUX_RPM=	yes

SRC_DISTFILES=	# unavailable

DATADIR=	${PREFIX}/usr/share/qt47
DESCR=		${.CURDIR}/../../devel/linux-c6-qt47/pkg-descr

post-patch:
	@${RM} -r ${WRKSRC}/usr/share/icons

.include <bsd.port.mk>
