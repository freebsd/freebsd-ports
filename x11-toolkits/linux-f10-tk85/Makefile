# Created by: bsam
# $FreeBSD: head/x11-toolkits/linux-f10-tk85/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	tk
PORTVERSION=	8.5.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

PKGNAMESUFFIX=	85

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Graphical toolkit for TCL (Linux Fedora 10)

CONFLICTS=	linux-f8-tk84-[0-9]*

USE_LINUX=	f10
USE_LINUX_RPM=	yes
USE_LINUX_RPM_BAD_PERMS=	yes
USE_LINUX_APPS=	xorglibs

RPMVERSION=	5.fc10
BRANELF_FILES=	usr/bin/wish8.5
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>
