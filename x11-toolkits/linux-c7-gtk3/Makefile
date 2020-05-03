# $FreeBSD$

PORTNAME=	gtk3
PORTVERSION=	3.22.30
DISTVERSIONSUFFIX=	-5.el7
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 3.X (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	at-spi2-atk atk cairo-gobject fontconfig freetype gdkpixbuf2 \
		libepoxy libxkbcommon pango wayland xorglibs
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-immodules-${DISTVERSIONFULL}

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
