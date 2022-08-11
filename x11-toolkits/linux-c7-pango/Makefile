PORTNAME=	pango
PORTVERSION=	1.42.4
DISTVERSIONSUFFIX=	-4.el7_7
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Pango library (Linux CentOS ${LINUX_DIST_VER})

USES=		cpe linux:c7
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
USE_LINUX=	cairo fontconfig freetype fribidi harfbuzz libthai xorglibs
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
