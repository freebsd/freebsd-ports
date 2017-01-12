# Created by: bsam
# $FreeBSD$

PORTNAME=	xorg-libs
PORTVERSION=	7.4
PORTREVISION=	7
CATEGORIES=	x11 linux
LIB_DISTFILES=	libICE-1.0.6-1.el6${EXTRACT_SUFX} \
		libSM-1.2.1-2.el6${EXTRACT_SUFX} \
		libX11-1.6.3-2.el6${EXTRACT_SUFX} \
		libXScrnSaver-1.2.2-2.el6${EXTRACT_SUFX} \
		libXau-1.0.6-4.el6${EXTRACT_SUFX} \
		libXaw-1.0.11-2.el6${EXTRACT_SUFX} \
		libXcomposite-0.4.3-4.el6${EXTRACT_SUFX} \
		libXcursor-1.1.14-2.1.el6${EXTRACT_SUFX} \
		libXdamage-1.1.3-4.el6${EXTRACT_SUFX} \
		libXdmcp-1.1.1-3.el6${EXTRACT_SUFX} \
		libXevie-1.0.3-4.el6${EXTRACT_SUFX} \
		libXext-1.3.3-1.el6${EXTRACT_SUFX} \
		libXfixes-5.0.1-2.1.el6${EXTRACT_SUFX} \
		libXfont-1.5.1-2.el6${EXTRACT_SUFX} \
		libXft-2.3.2-1.el6${EXTRACT_SUFX} \
		libXi-1.7.4-1.el6${EXTRACT_SUFX} \
		libXinerama-1.1.3-2.1.el6${EXTRACT_SUFX} \
		libXmu-1.1.1-2.el6${EXTRACT_SUFX} \
		libXp-1.0.2-2.1.el6${EXTRACT_SUFX} \
		libXpm-3.5.10-2.el6${EXTRACT_SUFX} \
		libXrandr-1.4.2-1.el6${EXTRACT_SUFX} \
		libXrender-0.9.8-2.1.el6_8.1${EXTRACT_SUFX} \
		libXres-1.0.7-2.1.el6${EXTRACT_SUFX} \
		libXt-1.1.4-6.1.el6${EXTRACT_SUFX} \
		libXtst-1.2.2-2.1.el6${EXTRACT_SUFX} \
		libXv-1.0.9-2.1.el6${EXTRACT_SUFX} \
		libXvMC-1.0.8-2.1.el6${EXTRACT_SUFX} \
		libXxf86dga-1.1.4-2.1.el6${EXTRACT_SUFX} \
		libXxf86misc-1.0.3-4.el6${EXTRACT_SUFX} \
		libXxf86vm-1.1.3-2.1.el6${EXTRACT_SUFX} \
		libfontenc-1.1.2-3.el6${EXTRACT_SUFX} \
		libxcb-1.11-2.el6${EXTRACT_SUFX} \
		libxkbfile-1.0.6-1.1.el6${EXTRACT_SUFX}
SRC_DISTFILES=	libICE-1.0.6-1.el6.src.rpm:SOURCE \
		libSM-1.2.1-2.el6.src.rpm:SOURCE \
		libX11-1.6.3-2.el6.src.rpm:SOURCE \
		libXScrnSaver-1.2.2-2.el6.src.rpm:SOURCE \
		libXau-1.0.6-4.el6.src.rpm:SOURCE \
		libXaw-1.0.11-2.el6.src.rpm:SOURCE \
		libXcomposite-0.4.3-4.el6.src.rpm:SOURCE \
		libXcursor-1.1.14-2.1.el6.src.rpm:SOURCE \
		libXdamage-1.1.3-4.el6.src.rpm:SOURCE \
		libXdmcp-1.1.1-3.el6.src.rpm:SOURCE \
		libXevie-1.0.3-4.el6.src.rpm:SOURCE \
		libXext-1.3.3-1.el6.src.rpm:SOURCE \
		libXfixes-5.0.1-2.1.el6.src.rpm:SOURCE \
		libXfont-1.5.1-2.el6.src.rpm:SOURCE \
		libXft-2.3.2-1.el6.src.rpm:SOURCE \
		libXi-1.7.4-1.el6.src.rpm:SOURCE \
		libXinerama-1.1.3-2.1.el6.src.rpm:SOURCE \
		libXmu-1.1.1-2.el6.src.rpm:SOURCE \
		libXp-1.0.2-2.1.el6.src.rpm:SOURCE \
		libXpm-3.5.10-2.el6.src.rpm:SOURCE \
		libXrandr-1.4.2-1.el6.src.rpm:SOURCE \
		libXrender-0.9.8-2.1.el6_8.1.src.rpm:SOURCE \
		libXres-1.0.7-2.1.el6.src.rpm:SOURCE \
		libXt-1.1.4-6.1.el6.src.rpm:SOURCE \
		libXtst-1.2.2-2.1.el6.src.rpm:SOURCE \
		libXv-1.0.9-2.1.el6.src.rpm:SOURCE \
		libXvMC-1.0.8-2.1.el6.src.rpm:SOURCE \
		libXxf86dga-1.1.4-2.1.el6.src.rpm:SOURCE \
		libXxf86misc-1.0.3-4.el6.src.rpm:SOURCE \
		libXxf86vm-1.1.3-2.1.el6.src.rpm:SOURCE \
		libfontenc-1.1.2-3.el6.src.rpm:SOURCE \
		libxcb-1.11-2.el6.src.rpm:SOURCE \
		libxkbfile-1.0.6-1.1.el6.src.rpm:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Xorg libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-xorg-libs-[0-9]* linux-f8-xorg-libs-[0-9]* linux-f10-xorg-libs-[0-9]*

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig
USE_LINUX_RPM=	yes

.include <bsd.port.mk>
