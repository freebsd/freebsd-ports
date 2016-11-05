# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	gtk2
PORTVERSION=	2.24.28
PORTREVISION=	2
CATEGORIES=	x11-toolkits linux
LIB_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-immodules-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	8.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	atk gdkpixbuf2 pango xorglibs
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr

.include <bsd.port.mk>
