# New ports collection makefile for:	linux-xorg-libs
# Date created:				$Date$
# Whom:					bsam@ipt.ru
#
# $FreeBSD$
#

PORTNAME=		xorg-libs
PORTVERSION=		6.8.2
PORTREVISION=		2
CATEGORIES=		x11 linux
DISTFILES=		xorg-x11-libs-${PORTVERSION}-37.FC4.49.2.${LINUX_RPM_ARCH}.rpm \
			xorg-x11-deprecated-libs-6.8.2-31.${LINUX_RPM_ARCH}.rpm

MAINTAINER=		freebsd-emulation@FreeBSD.org
COMMENT=		Xorg libraries, linux binaries

CONFLICTS=		linux-XFree86-libs

USE_LINUX_RPM=		yes
LINUX_DIST_VER=		4
INSTALLS_SHLIB=		yes

SRC_DISTFILES=		xorg-x11-6.8.2-37.FC4.49.2.src.rpm

.include <bsd.port.mk>
