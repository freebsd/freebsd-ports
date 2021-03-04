# $FreeBSD$

PORTNAME=	gtk3
PORTVERSION=	3.22.30
DISTVERSIONSUFFIX=	-6.el7
PORTREVISION=	3
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 3.X (Linux CentOS ${LINUX_DIST_VER})

RUN_DEPENDS=	hicolor-icon-theme>0:misc/hicolor-icon-theme \
		adwaita-icon-theme>0:x11-themes/adwaita-icon-theme

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	at-spi2-atk atk cairo-gobject fontconfig freetype gdkpixbuf2 \
		libepoxy librsvg2 libxkbcommon pango wayland xorglibs
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-immodules-${DISTVERSIONFULL}

DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
