# New ports collection makefile for:	x11-toolkits/linux-f8-gtk
# Date created:				2008-04-04
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	1.2.10
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Gtk library (Linux Fedora 8)

CONFLICTS=	linux-gtk-[0-9]* linux-f10-gtk-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_NAME=	${PORTNAME}+
LINUX_DIST_VER=	8
RPMVERSION=	59.fc8
USE_LDCONFIG=	yes
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
