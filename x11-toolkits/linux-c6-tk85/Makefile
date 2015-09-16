# Created by: bsam
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.5.7
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
PKGNAMESUFFIX=	85

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Graphical toolkit for TCL (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-tk85-[0-9]*

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_RPM_BAD_PERMS=	yes
USE_LINUX_APPS=	xorglibs

RPMVERSION=	5.el6
BRANDELF_FILES=	#usr/bin/wish8.5
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>
