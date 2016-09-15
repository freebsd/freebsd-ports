# Created by: bsam
# $FreeBSD$

PORTNAME=	xorg-libs
PORTVERSION=	7.4
PORTREVISION=	2
CATEGORIES=	x11 linux
BIN_DISTFILES=	libICE-1.0.4-4.fc10${EXTRACT_SUFX} \
		libFS-1.0.1-2.fc10${EXTRACT_SUFX} \
		libSM-1.1.0-2.fc10${EXTRACT_SUFX} \
		libX11-1.1.5-4.fc10${EXTRACT_SUFX} \
		libXScrnSaver-1.1.3-1.fc10${EXTRACT_SUFX} \
		libXTrap-1.0.0-6.fc10${EXTRACT_SUFX} \
		libXau-1.0.4-1.fc10${EXTRACT_SUFX} \
		libXaw-1.0.4-3.fc10${EXTRACT_SUFX} \
		libXcomposite-0.4.0-5.fc10${EXTRACT_SUFX} \
		libXcursor-1.1.9-3.fc10${EXTRACT_SUFX} \
		libXdamage-1.1.1-4.fc9${EXTRACT_SUFX} \
		libXdmcp-1.0.2-6.fc10${EXTRACT_SUFX} \
		libXevie-1.0.2-4.fc10${EXTRACT_SUFX} \
		libXext-1.0.4-1.fc9${EXTRACT_SUFX} \
		libXfixes-4.0.3-4.fc10${EXTRACT_SUFX} \
		libXfont-1.3.3-1.fc10${EXTRACT_SUFX} \
		libXft-2.1.13-1.fc10${EXTRACT_SUFX} \
		libXi-1.1.3-4.fc9${EXTRACT_SUFX} \
		libXinerama-1.0.3-2.fc10${EXTRACT_SUFX} \
		libXmu-1.0.4-1.fc9${EXTRACT_SUFX} \
		libXp-1.0.0-11.fc9${EXTRACT_SUFX} \
		libXpm-3.5.7-4.fc9${EXTRACT_SUFX} \
		libXrandr-1.2.3-1.fc10${EXTRACT_SUFX} \
		libXrender-0.9.4-3.fc9${EXTRACT_SUFX} \
		libXres-1.0.3-5.fc10${EXTRACT_SUFX} \
		libXt-1.0.5-1.fc10${EXTRACT_SUFX} \
		libXtst-1.0.3-3.fc9${EXTRACT_SUFX} \
		libXv-1.0.4-1.fc10${EXTRACT_SUFX} \
		libXvMC-1.0.4-5.fc10${EXTRACT_SUFX} \
		libXxf86dga-1.0.2-3.fc10${EXTRACT_SUFX} \
		libXxf86misc-1.0.1-6.fc10${EXTRACT_SUFX} \
		libXxf86vm-1.0.2-1.fc10${EXTRACT_SUFX} \
		libfontenc-1.0.4-6.fc10${EXTRACT_SUFX} \
		libxcb-1.1.91-5.fc10${EXTRACT_SUFX} \
		libxkbfile-1.0.4-5.fc9${EXTRACT_SUFX} \
		mesa-libGLw-6.5.1-5.fc9${EXTRACT_SUFX}
SRC_DISTFILES=	libICE-1.0.4-4.fc10.src.rpm:SOURCE \
		libFS-1.0.1-2.fc10.src.rpm:SOURCE \
		libSM-1.1.0-2.fc10.src.rpm:SOURCE \
		libX11-1.1.5-4.fc10.src.rpm:SOURCE \
		libXScrnSaver-1.1.3-1.fc10.src.rpm:SOURCE \
		libXTrap-1.0.0-6.fc10.src.rpm:SOURCE \
		libXau-1.0.4-1.fc10.src.rpm:SOURCE \
		libXaw-1.0.4-3.fc10.src.rpm:SOURCE \
		libXcomposite-0.4.0-5.fc10.src.rpm:SOURCE \
		libXcursor-1.1.9-3.fc10.src.rpm:SOURCE \
		libXdamage-1.1.1-4.fc9.src.rpm:SOURCE \
		libXdmcp-1.0.2-6.fc10.src.rpm:SOURCE \
		libXevie-1.0.2-4.fc10.src.rpm:SOURCE \
		libXext-1.0.4-1.fc9.src.rpm:SOURCE \
		libXfixes-4.0.3-4.fc10.src.rpm:SOURCE \
		libXfont-1.3.3-1.fc10.src.rpm:SOURCE \
		libXft-2.1.13-1.fc10.src.rpm:SOURCE \
		libXi-1.1.3-4.fc9.src.rpm:SOURCE \
		libXinerama-1.0.3-2.fc10.src.rpm:SOURCE \
		libXmu-1.0.4-1.fc9.src.rpm:SOURCE \
		libXp-1.0.0-11.fc9.src.rpm:SOURCE \
		libXpm-3.5.7-4.fc9.src.rpm:SOURCE \
		libXrandr-1.2.3-1.fc10.src.rpm:SOURCE \
		libXrender-0.9.4-3.fc9.src.rpm:SOURCE \
		libXres-1.0.3-5.fc10.src.rpm:SOURCE \
		libXt-1.0.5-1.fc10.src.rpm:SOURCE \
		libXtst-1.0.3-3.fc9.src.rpm:SOURCE \
		libXv-1.0.4-1.fc10.src.rpm:SOURCE \
		libXvMC-1.0.4-5.fc10.src.rpm:SOURCE \
		libXxf86dga-1.0.2-3.fc10.src.rpm:SOURCE \
		libXxf86misc-1.0.1-6.fc10.src.rpm:SOURCE \
		libXxf86vm-1.0.2-1.fc10.src.rpm:SOURCE \
		libfontenc-1.0.4-6.fc10.src.rpm:SOURCE \
		libxcb-1.1.91-5.fc10.src.rpm:SOURCE \
		libxkbfile-1.0.4-5.fc9.src.rpm:SOURCE \
		mesa-libGLw-6.5.1-5.fc9.src.rpm:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Xorg libraries (Linux Fedora 10)

CONFLICTS=	linux-xorg-libs-[0-9]* linux-f8-xorg-libs-[0-9]*

USES=		linux:f10
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig
USE_LINUX_RPM=	nolib

.include <bsd.port.mk>
