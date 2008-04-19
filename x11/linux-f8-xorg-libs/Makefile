# New ports collection makefile for:	linux-xorg-libs
# Date created:				$Date$
# Whom:					bsam@ipt.ru
#
# $FreeBSD$
#

PORTNAME=		xorg-libs
PORTVERSION=		6.8.2
PORTREVISION=		5
CATEGORIES=		x11 linux
DISTFILES=		xorg-x11-libs-${PORTVERSION}-37.FC4.49.2.1.${LINUX_RPM_ARCH}.rpm \
			xorg-x11-deprecated-libs-6.8.2-31.${LINUX_RPM_ARCH}.rpm

MAINTAINER=		freebsd-emulation@FreeBSD.org
COMMENT=		Xorg libraries, linux binaries

RUN_DEPENDS=		${LINUXBASE}/usr/lib/libfontconfig.so.1:${PORTSDIR}/x11-fonts/linux-fontconfig

CONFLICTS=		linux-XFree86-libs

USE_LINUX_RPM=		yes
LINUX_DIST_VER=		4
USE_LDCONFIG=		yes

SRC_DISTFILES=		xorg-x11-6.8.2-37.FC4.49.2.1.src.rpm

.include <bsd.port.mk>
