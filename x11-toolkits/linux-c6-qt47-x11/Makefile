# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	qt47-x11
PORTVERSION=	4.7.2
PORTREVISION=	3
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	https://www.mirrorservice.org/sites/dl.atrpms.net/el6-x86_64/atrpms/testing/\
		https://www.mirrorservice.org/sites/dl.atrpms.net/el6-i386/atrpms/testing/ \
		LOCAL/xmj
DIST_SUBDIR=	rpm/${LINUX_RPM_ARCH}/atrpms/6

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS 6)

SRC_DISTFILES=	# unretrievable.

RPMVERSION=	1_18.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	alsalib dri fontconfig jpeg openssl png qt47 tiff xorglibs
USE_LINUX_RPM=	yes

DESCR=	${.CURDIR}/../../devel/qt4/pkg-descr

post-patch:
	${RM} ${WRKSRC}/usr/share/qt47/translations/qt_help_*.qm

.include <bsd.port.mk>
