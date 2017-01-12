# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	gtk2
PORTVERSION=	2.24.23
PORTREVISION=	6
CATEGORIES=	x11-toolkits linux
LIB_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-engines-2.18.4-5.el6.centos${EXTRACT_SUFX} \
		${PORTNAME}-immodules-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-gtk2-[0-9]* linux-f8-gtk2-[0-9]* linux-f10-gtk2-[0-9]*

RPMVERSION=	8.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	atk gdkpixbuf2 pango xorglibs
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr

.include <bsd.port.mk>
