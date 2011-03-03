# New ports collection makefile for:	linux-xorg-libs
# Date created:				$Date$
# Whom:					bsam@ipt.ru
#
# $FreeBSD$
#

PORTNAME=		xorg-libs
PORTVERSION=		6.8.2
PORTREVISION=		7
CATEGORIES=		x11 linux
MASTER_SITES=		CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTFILES=		xorg-x11-libs-${PORTVERSION}-37.FC4.49.2.1.${LINUX_RPM_ARCH}.rpm \
			xorg-x11-deprecated-libs-6.8.2-31.${LINUX_RPM_ARCH}.rpm

MAINTAINER=		freebsd-emulation@FreeBSD.org
COMMENT=		Xorg libraries, linux binaries

CONFLICTS=		linux-XFree86-libs-[0-9]* linux-f8-xorg-libs-[0-9]* linux-f10-xorg-libs-[0-9]*

USE_LINUX_RPM=		yes
USE_LINUX_APPS=		fontconfig
LINUX_DIST_VER=		4
USE_LDCONFIG=		yes

SRC_DISTFILES=		xorg-x11-6.8.2-37.FC4.49.2.1.src.rpm

.include <bsd.port.mk>
