# Created by: bsam
# $FreeBSD$

PORTNAME=	xorg-libs
PORTVERSION=	7.4
PORTREVISION=	10
CATEGORIES=	x11 linux
LIB_DISTNAMES=	libICE-1.0.6-1.el6 \
		libSM-1.2.1-2.el6 \
		libX11-1.6.4-3.el6 \
		libXScrnSaver-1.2.2-2.el6 \
		libXau-1.0.6-4.el6 \
		libXaw-1.0.11-2.el6 \
		libXcomposite-0.4.3-4.el6 \
		libXcursor-1.1.14-2.1.el6 \
		libXdamage-1.1.3-4.el6 \
		libXdmcp-1.1.1-3.el6 \
		libXevie-1.0.3-4.el6 \
		libXext-1.3.3-1.el6 \
		libXfixes-5.0.3-1.el6 \
		libXfont-1.5.1-2.el6 \
		libXft-2.3.2-1.el6 \
		libXi-1.7.8-1.el6 \
		libXinerama-1.1.3-2.1.el6 \
		libXmu-1.1.1-2.el6 \
		libXp-1.0.2-2.1.el6 \
		libXpm-3.5.10-2.el6 \
		libXrandr-1.5.1-1.el6 \
		libXrender-0.9.10-1.el6 \
		libXres-1.0.7-2.1.el6 \
		libXt-1.1.4-6.1.el6 \
		libXtst-1.2.3-1.el6 \
		libXv-1.0.11-1.el6 \
		libXvMC-1.0.10-1.el6 \
		libXxf86dga-1.1.4-2.1.el6 \
		libXxf86misc-1.0.3-4.el6 \
		libXxf86vm-1.1.3-2.1.el6 \
		libfontenc-1.1.2-3.el6 \
		libxcb-1.12-4.el6 \
		libxkbfile-1.0.6-1.1.el6
SHARE_DISTNAMES=libX11-common-1.6.4-3.el6
SRC_DISTFILES=	libICE-1.0.6-1.el6${SRC_SUFX}:SOURCE \
		libSM-1.2.1-2.el6${SRC_SUFX}:SOURCE \
		libX11-1.6.4-3.el6${SRC_SUFX}:SOURCE \
		libXScrnSaver-1.2.2-2.el6${SRC_SUFX}:SOURCE \
		libXau-1.0.6-4.el6${SRC_SUFX}:SOURCE \
		libXaw-1.0.11-2.el6${SRC_SUFX}:SOURCE \
		libXcomposite-0.4.3-4.el6${SRC_SUFX}:SOURCE \
		libXcursor-1.1.14-2.1.el6${SRC_SUFX}:SOURCE \
		libXdamage-1.1.3-4.el6${SRC_SUFX}:SOURCE \
		libXdmcp-1.1.1-3.el6${SRC_SUFX}:SOURCE \
		libXevie-1.0.3-4.el6${SRC_SUFX}:SOURCE \
		libXext-1.3.3-1.el6${SRC_SUFX}:SOURCE \
		libXfixes-5.0.3-1.el6${SRC_SUFX}:SOURCE \
		libXfont-1.5.1-2.el6${SRC_SUFX}:SOURCE \
		libXft-2.3.2-1.el6${SRC_SUFX}:SOURCE \
		libXi-1.7.8-1.el6${SRC_SUFX}:SOURCE \
		libXinerama-1.1.3-2.1.el6${SRC_SUFX}:SOURCE \
		libXmu-1.1.1-2.el6${SRC_SUFX}:SOURCE \
		libXp-1.0.2-2.1.el6${SRC_SUFX}:SOURCE \
		libXpm-3.5.10-2.el6${SRC_SUFX}:SOURCE \
		libXrandr-1.5.1-1.el6${SRC_SUFX}:SOURCE \
		libXrender-0.9.10-1.el6${SRC_SUFX}:SOURCE \
		libXres-1.0.7-2.1.el6${SRC_SUFX}:SOURCE \
		libXt-1.1.4-6.1.el6${SRC_SUFX}:SOURCE \
		libXtst-1.2.3-1.el6${SRC_SUFX}:SOURCE \
		libXv-1.0.11-1.el6${SRC_SUFX}:SOURCE \
		libXvMC-1.0.10-1.el6${SRC_SUFX}:SOURCE \
		libXxf86dga-1.1.4-2.1.el6${SRC_SUFX}:SOURCE \
		libXxf86misc-1.0.3-4.el6${SRC_SUFX}:SOURCE \
		libXxf86vm-1.1.3-2.1.el6${SRC_SUFX}:SOURCE \
		libfontenc-1.1.2-3.el6${SRC_SUFX}:SOURCE \
		libxcb-1.12-4.el6${SRC_SUFX}:SOURCE \
		libxkbfile-1.0.6-1.1.el6${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Xorg libraries (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} -r ${WRKSRC}/usr/share/icons

.include <bsd.port.mk>
