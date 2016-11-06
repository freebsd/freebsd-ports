# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	pango
PORTVERSION=	1.36.8
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org

COMMENT=	Pango library (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	2.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	cairo fontconfig harfbuzz libthai xorglibs
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
