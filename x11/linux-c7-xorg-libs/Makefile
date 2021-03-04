# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	xorg-libs
PORTVERSION=	7.7
PORTREVISION=	9
CATEGORIES=	x11 linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Xorg libraries (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	libICE-1.0.9-9.el7 \
		libSM-1.2.2-2.el7 \
		libX11-1.6.7-3.el7_9 \
		libXScrnSaver-1.2.2-6.1.el7 \
		libXau-1.0.8-2.1.el7 \
		libXaw-1.0.13-4.el7 \
		libXcomposite-0.4.4-4.1.el7 \
		libXcursor-1.1.15-1.el7 \
		libXdamage-1.1.4-4.1.el7 \
		libXdmcp-1.1.2-6.el7 \
		libXevie-1.0.3-7.1.el7 \
		libXext-1.3.3-3.el7 \
		libXfixes-5.0.3-1.el7 \
		libXfont-1.5.4-1.el7 \
		libXfont2-2.0.3-1.el7 \
		libXft-2.3.2-2.el7 \
		libXi-1.7.9-1.el7 \
		libXinerama-1.1.3-2.1.el7 \
		libXmu-1.1.2-2.el7 \
		libXp-1.0.2-2.1.el7 \
		libXpm-3.5.12-1.el7 \
		libXrandr-1.5.1-2.el7 \
		libXrender-0.9.10-1.el7 \
		libXres-1.2.0-1.el7 \
		libXt-1.1.5-3.el7 \
		libXtst-1.2.3-1.el7 \
		libXv-1.0.11-1.el7 \
		libXvMC-1.0.10-1.el7 \
		libXxf86dga-1.1.4-2.1.el7 \
		libXxf86misc-1.0.3-7.1.el7 \
		libXxf86vm-1.1.4-1.el7 \
		libfontenc-1.1.3-3.el7 \
		libxcb-1.13-1.el7 \
		libxkbfile-1.0.9-3.el7 \
		libxshmfence-1.2-1.el7
SHARE_DISTNAMES=libX11-common-1.6.7-2.el7 \
		xkeyboard-config-2.24-1.el7
SRC_DISTFILES=	libICE-1.0.9-9.el7${SRC_SUFX}:SOURCE \
		libSM-1.2.2-2.el7${SRC_SUFX}:SOURCE \
		libX11-1.6.7-3.el7_9${SRC_SUFX}:SOURCE \
		libXScrnSaver-1.2.2-6.1.el7${SRC_SUFX}:SOURCE \
		libXau-1.0.8-2.1.el7${SRC_SUFX}:SOURCE \
		libXaw-1.0.13-4.el7${SRC_SUFX}:SOURCE \
		libXcomposite-0.4.4-4.1.el7${SRC_SUFX}:SOURCE \
		libXcursor-1.1.15-1.el7${SRC_SUFX}:SOURCE \
		libXdamage-1.1.4-4.1.el7${SRC_SUFX}:SOURCE \
		libXdmcp-1.1.2-6.el7${SRC_SUFX}:SOURCE \
		libXevie-1.0.3-7.1.el7${SRC_SUFX}:SOURCE \
		libXext-1.3.3-3.el7${SRC_SUFX}:SOURCE \
		libXfixes-5.0.3-1.el7${SRC_SUFX}:SOURCE \
		libXfont-1.5.4-1.el7${SRC_SUFX}:SOURCE \
		libXft-2.3.2-2.el7${SRC_SUFX}:SOURCE \
		libXi-1.7.9-1.el7${SRC_SUFX}:SOURCE \
		libXinerama-1.1.3-2.1.el7${SRC_SUFX}:SOURCE \
		libXmu-1.1.2-2.el7${SRC_SUFX}:SOURCE \
		libXp-1.0.2-2.1.el7${SRC_SUFX}:SOURCE \
		libXpm-3.5.12-1.el7${SRC_SUFX}:SOURCE \
		libXrandr-1.5.1-2.el7${SRC_SUFX}:SOURCE \
		libXrender-0.9.10-1.el7${SRC_SUFX}:SOURCE \
		libXres-1.2.0-1.el7${SRC_SUFX}:SOURCE \
		libXt-1.1.5-3.el7${SRC_SUFX}:SOURCE \
		libXtst-1.2.3-1.el7${SRC_SUFX}:SOURCE \
		libXv-1.0.11-1.el7${SRC_SUFX}:SOURCE \
		libXvMC-1.0.10-1.el7${SRC_SUFX}:SOURCE \
		libXxf86dga-1.1.4-2.1.el7${SRC_SUFX}:SOURCE \
		libXxf86misc-1.0.3-7.1.el7${SRC_SUFX}:SOURCE \
		libXxf86vm-1.1.4-1.el7${SRC_SUFX}:SOURCE \
		libfontenc-1.1.3-3.el7${SRC_SUFX}:SOURCE \
		libxcb-1.13-1.el7${SRC_SUFX}:SOURCE \
		libxkbfile-1.0.9-3.el7${SRC_SUFX}:SOURCE \
		libxshmfence-1.2-1.el7${SRC_SUFX}:SOURCE \
		xkeyboard-config-2.24-1.el7${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${RM} -r ${WRKSRC}/usr/share/icons

.include <bsd.port.mk>
