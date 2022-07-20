PORTNAME=	gtk2
PORTVERSION=	2.24.31
DISTVERSIONSUFFIX=	-1.el7
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X (Linux CentOS ${LINUX_DIST_VER})

USES=		cpe linux:c7
CPE_VENDOR=	gnome
CPE_PRODUCT=	gtk
USE_LDCONFIG=	yes
USE_LINUX=	atk gdkpixbuf2 pango xorglibs
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-immodules-${DISTVERSIONFULL}

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
