# New ports collection makefile for: linux-gtk
# Date created:         8 April 2000
# Whom:                 sada@FreeBSD.org
# Based on:		emulators/linux_base by marcel@FreeBSD.org
#			& multimedia/xmovie by sanpei@sanpei.org
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	1.2.10
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
DISTNAME=	gtk+-${PORTVERSION}-33

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of the Gtk lib

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
USE_XLIB=	yes

.include <bsd.port.mk>
