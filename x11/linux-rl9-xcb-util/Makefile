PORTNAME=	xcb-util
PORTVERSION=	0.4.0
DISTVERSIONSUFFIX=	-19.el9
PORTREVISION=	2
CATEGORIES=	x11 linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	libxcb/libX11 extension/replacement libraries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://xcb.freedesktop.org/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL} \
		${PORTNAME}-cursor-0.1.4-3.el9 \
		${PORTNAME}-image-0.4.0-19.el9.0.1 \
		${PORTNAME}-keysyms-0.4.0-17.el9 \
		${PORTNAME}-renderutil-0.3.9-20.el9.0.1 \
		${PORTNAME}-wm-0.4.1-22.el9

SRC_DISTFILES=	${PORTNAME}-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE \
		${PORTNAME}-cursor-0.1.4-3.el9${SRC_SUFX}:SOURCE \
		${PORTNAME}-image-0.4.0-19.el9.0.1${SRC_SUFX}:SOURCE \
		${PORTNAME}-keysyms-0.4.0-17.el9${SRC_SUFX}:SOURCE \
		${PORTNAME}-renderutil-0.3.9-20.el9.0.1${SRC_SUFX}:SOURCE \
		${PORTNAME}-wm-0.4.1-22.el9${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
