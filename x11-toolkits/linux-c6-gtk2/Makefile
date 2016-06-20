# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	gtk2
PORTVERSION=	2.24.23
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
DISTFILES=	#
LIB_DISTFILES=	${DISTNAME}.${LINUX_RPM_ARCH}.rpm \
		${PORTNAME}-engines-2.18.4-5.el6.${LINUX_DIST}.${LINUX_RPM_ARCH}.rpm \
		pixman-0.32.8-1.el6.${LINUX_RPM_ARCH}.rpm \
		jasper-libs-1.900.1-16.el6_6.3.${LINUX_RPM_ARCH}.rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X  (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-gtk2-[0-9]* linux-f8-gtk2-[0-9]* linux-f10-gtk2-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_APPS=	atk gdkpixbuf2 jpeg pango png tiff xorglibs
USE_LINUX_RPM=	yes
RPMVERSION=	8.el6
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	gtk2-${PORTVERSION}-${RPMVERSION}.src.rpm:SOURCE \
		pixman-0.32.8-1.el6.src.rpm:SOURCE \
		jasper-1.900.1-16.el6_6.3.src.rpm:SOURCE
.endif

.include <bsd.port.mk>
