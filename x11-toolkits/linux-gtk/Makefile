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
PORTREVISION=	6
CATEGORIES=	x11-toolkits linux
DISTNAME=	gtk+-${PORTVERSION}-39

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of the Gtk lib

CONFLICTS=	linux-f8-gtk-[0-9]* linux-f10-gtk-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
