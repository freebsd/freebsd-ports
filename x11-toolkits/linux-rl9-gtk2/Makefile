PORTNAME=	gtk2
PORTVERSION=	2.24.33
DISTVERSIONSUFFIX=	-8.el9
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GTK+ library, version 2.X (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gtk.org/

USES=		cpe linux:rl9
CPE_VENDOR=	gnome
CPE_PRODUCT=	gtk
USE_LDCONFIG=	yes
USE_LINUX=	atk gdkpixbuf2 icu pango xorglibs
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-immodules-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}0/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
