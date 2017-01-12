# Created by: bsam
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.5.7
PORTREVISION=	3
CATEGORIES=	x11-toolkits linux
PKGNAMESUFFIX=	85

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Graphical toolkit for TCL (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-tk85-[0-9]*

RPMVERSION=	5.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes
USE_LINUX_RPM_BAD_PERMS=	yes

DATADIR=	${PREFIX}/usr/share/tk${PORTVERSION:R}
DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>
