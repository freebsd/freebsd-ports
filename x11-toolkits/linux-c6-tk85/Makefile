# Created by: bsam
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.5.7
CATEGORIES=	x11-toolkits linux
PKGNAMESUFFIX=	85

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Graphical toolkit for TCL (Linux CentOS ${LINUX_DIST_VER})

# XXX: someone should make libarchive be quiet about symlinks
EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

EXTRACT_CMD=	rpm2cpio.pl
EXTRACT_BEFORE_ARGS:=
EXTRACT_AFTER_ARGS=	| cpio -idm --insecure

CONFLICTS=	linux-f10-tk85-[0-9]*

USE_LINUX=	yes
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs

RPMVERSION=	5.el6
BRANELF_FILES=	#usr/bin/wish8.5
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr


.include <bsd.port.mk>
