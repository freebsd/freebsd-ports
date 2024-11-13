PORTNAME=	pango
PORTVERSION=	1.48.7
DISTVERSIONSUFFIX=	-3.el9
PORTREVISION=	1
CATEGORIES=	x11-toolkits linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Pango library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.pango.org/

USES=		cpe linux:rl9
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
USE_LINUX=	cairo fontconfig freetype fribidi harfbuzz libthai xorglibs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
