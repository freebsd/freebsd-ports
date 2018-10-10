# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	qt47-x11
PORTVERSION=	4.7.2
PORTREVISION=	6
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	LOCAL/tijl/atrpms:amd64,i386
SRC_DISTFILES=	# unavailable
DIST_SUBDIR=	atrpms

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform application and UI framework (Linux CentOS ${LINUX_DIST_VER})

DATADIR=	${PREFIX}/usr/share/qt47
DESCR=		${.CURDIR}/../../devel/qt4/pkg-descr
RPMVERSION=	1_18.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	alsalib dri fontconfig jpeg openssl png qt tiff xorglibs
USE_LINUX_RPM=	yes

post-patch:
	@${RM} -r ${WRKSRC}/usr/share/icons

.include <bsd.port.mk>
