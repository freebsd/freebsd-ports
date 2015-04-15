# Created by: bsam
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.5.7
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
PKGNAMESUFFIX=	85

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Graphical toolkit for TCL (Linux CentOS ${LINUX_DIST_VER})

EXTRACT_DEPENDS=rpm2archive:${PORTSDIR}/archivers/rpm4

CONFLICTS=	linux-f10-tk85-[0-9]*

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs

RPMVERSION=	5.el6
BRANDELF_FILES=	#usr/bin/wish8.5
USE_LDCONFIG=	yes

EXTRACT_CMD=	${LOCALBASE}/bin/rpm2archive
EXTRACT_BEFORE_ARGS=	<
EXTRACT_AFTER_ARGS=	| ${GZIP_CMD} -cd | ${TAR} xf - --no-same-owner --no-same-permissions

DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>
