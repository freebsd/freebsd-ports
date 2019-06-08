# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	gtk2
PORTVERSION=	2.24.23
DISTVERSIONSUFFIX=	-9.el6
PORTREVISION=	7
CATEGORIES=	x11-toolkits linux
LIB_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-engines-2.18.4-5.el6.centos \
		${PORTNAME}-immodules-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	atk gdkpixbuf2 pango xorglibs
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
