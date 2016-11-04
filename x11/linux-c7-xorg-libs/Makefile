# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	xorg-libs
PORTVERSION=	7.7
PORTREVISION=	1
CATEGORIES=	x11 linux
LIB_DISTFILES=	libICE-1.0.9-2.el7${EXTRACT_SUFX} \
		libSM-1.2.2-2.el7${EXTRACT_SUFX} \
		libX11-1.6.3-2.el7${EXTRACT_SUFX} \
		libXScrnSaver-1.2.2-6.1.el7${EXTRACT_SUFX} \
		libXau-1.0.8-2.1.el7${EXTRACT_SUFX} \
		libXaw-1.0.12-5.el7${EXTRACT_SUFX} \
		libXcomposite-0.4.4-4.1.el7${EXTRACT_SUFX} \
		libXcursor-1.1.14-2.1.el7${EXTRACT_SUFX} \
		libXdamage-1.1.4-4.1.el7${EXTRACT_SUFX} \
		libXdmcp-1.1.1-6.1.el7${EXTRACT_SUFX} \
		libXevie-1.0.3-7.1.el7${EXTRACT_SUFX} \
		libXext-1.3.3-3.el7${EXTRACT_SUFX} \
		libXfixes-5.0.1-2.1.el7${EXTRACT_SUFX} \
		libXfont-1.5.1-2.el7${EXTRACT_SUFX} \
		libXft-2.3.2-2.el7${EXTRACT_SUFX} \
		libXi-1.7.4-2.el7${EXTRACT_SUFX} \
		libXinerama-1.1.3-2.1.el7${EXTRACT_SUFX} \
		libXmu-1.1.2-2.el7${EXTRACT_SUFX} \
		libXp-1.0.2-2.1.el7${EXTRACT_SUFX} \
		libXpm-3.5.11-3.el7${EXTRACT_SUFX} \
		libXrandr-1.4.2-2.el7${EXTRACT_SUFX} \
		libXrender-0.9.8-2.1.el7${EXTRACT_SUFX} \
		libXres-1.0.7-2.1.el7${EXTRACT_SUFX} \
		libXt-1.1.4-6.1.el7${EXTRACT_SUFX} \
		libXtst-1.2.2-2.1.el7${EXTRACT_SUFX} \
		libXv-1.0.10-2.el7${EXTRACT_SUFX} \
		libXvMC-1.0.8-2.1.el7${EXTRACT_SUFX} \
		libXxf86dga-1.1.4-2.1.el7${EXTRACT_SUFX} \
		libXxf86misc-1.0.3-7.1.el7${EXTRACT_SUFX} \
		libXxf86vm-1.1.3-2.1.el7${EXTRACT_SUFX} \
		libfontenc-1.1.2-3.el7${EXTRACT_SUFX} \
		libxcb-1.11-4.el7${EXTRACT_SUFX} \
		libxkbfile-1.0.8-5.el7${EXTRACT_SUFX} \
		libxshmfence-1.2-1.el7${EXTRACT_SUFX}
SRC_DISTFILES=	libICE-1.0.9-2.el7${SRC_SUFX}:SOURCE \
		libSM-1.2.2-2.el7${SRC_SUFX}:SOURCE \
		libX11-1.6.3-2.el7${SRC_SUFX}:SOURCE \
		libXScrnSaver-1.2.2-6.1.el7${SRC_SUFX}:SOURCE \
		libXau-1.0.8-2.1.el7${SRC_SUFX}:SOURCE \
		libXaw-1.0.12-5.el7${SRC_SUFX}:SOURCE \
		libXcomposite-0.4.4-4.1.el7${SRC_SUFX}:SOURCE \
		libXcursor-1.1.14-2.1.el7${SRC_SUFX}:SOURCE \
		libXdamage-1.1.4-4.1.el7${SRC_SUFX}:SOURCE \
		libXdmcp-1.1.1-6.1.el7${SRC_SUFX}:SOURCE \
		libXevie-1.0.3-7.1.el7${SRC_SUFX}:SOURCE \
		libXext-1.3.3-3.el7${SRC_SUFX}:SOURCE \
		libXfixes-5.0.1-2.1.el7${SRC_SUFX}:SOURCE \
		libXfont-1.5.1-2.el7${SRC_SUFX}:SOURCE \
		libXft-2.3.2-2.el7${SRC_SUFX}:SOURCE \
		libXi-1.7.4-2.el7${SRC_SUFX}:SOURCE \
		libXinerama-1.1.3-2.1.el7${SRC_SUFX}:SOURCE \
		libXmu-1.1.2-2.el7${SRC_SUFX}:SOURCE \
		libXp-1.0.2-2.1.el7${SRC_SUFX}:SOURCE \
		libXpm-3.5.11-3.el7${SRC_SUFX}:SOURCE \
		libXrandr-1.4.2-2.el7${SRC_SUFX}:SOURCE \
		libXrender-0.9.8-2.1.el7${SRC_SUFX}:SOURCE \
		libXres-1.0.7-2.1.el7${SRC_SUFX}:SOURCE \
		libXt-1.1.4-6.1.el7${SRC_SUFX}:SOURCE \
		libXtst-1.2.2-2.1.el7${SRC_SUFX}:SOURCE \
		libXv-1.0.10-2.el7${SRC_SUFX}:SOURCE \
		libXvMC-1.0.8-2.1.el7${SRC_SUFX}:SOURCE \
		libXxf86dga-1.1.4-2.1.el7${SRC_SUFX}:SOURCE \
		libXxf86misc-1.0.3-7.1.el7${SRC_SUFX}:SOURCE \
		libXxf86vm-1.1.3-2.1.el7${SRC_SUFX}:SOURCE \
		libfontenc-1.1.2-3.el7${SRC_SUFX}:SOURCE \
		libxcb-1.11-4.el7${SRC_SUFX}:SOURCE \
		libxkbfile-1.0.8-5.el7${SRC_SUFX}:SOURCE \
		libxshmfence-1.2-1.el7${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Xorg libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig
USE_LINUX_RPM=	yes

.include <bsd.port.mk>
