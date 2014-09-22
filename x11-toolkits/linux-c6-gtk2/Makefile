# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	gtk2
PORTVERSION=	2.20.1
CATEGORIES=	x11-toolkits linux
DISTFILES=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}.${LINUX_RPM_ARCH}.rpm \
		${PORTNAME}-engines-2.18.4-5.el6.${LINUX_DIST}.${LINUX_RPM_ARCH}.rpm \
		pixman-0.26.2-5.el6_4.${LINUX_RPM_ARCH}.rpm \
		jasper-libs-1.900.1-15.el6_1.1.${LINUX_RPM_ARCH}.rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X  (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-gtk2-[0-9]* linux-f8-gtk2-[0-9]* linux-f10-gtk2-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_APPS=	png jpeg tiff xorglibs pango atk
USE_LINUX_RPM=	yes
RPMVERSION=	4.el6
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr

.include <bsd.port.mk>
