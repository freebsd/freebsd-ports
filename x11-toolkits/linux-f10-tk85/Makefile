# Created by: bsam
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.5.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux

PKGNAMESUFFIX=	85

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Graphical toolkit for TCL (Linux Fedora 10)

CONFLICTS=	linux-f8-tk84-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX_RPM_BAD_PERMS=	yes
USE_LINUX=	xorglibs

RPMVERSION=	5.fc10
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>
