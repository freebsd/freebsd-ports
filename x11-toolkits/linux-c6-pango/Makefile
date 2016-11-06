# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	pango
PORTVERSION=	1.28.1
PORTREVISION=	6
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org

COMMENT=	Pango library (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-pango-[0-9]* linux-f10-pango-[0-9]*

RPMVERSION=	11.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	cairo fontconfig libthai xorglibs
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
