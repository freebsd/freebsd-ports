PORTNAME=	xorg-libs
PORTVERSION=	7.7
PORTREVISION=	1
CATEGORIES=	x11 linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Xorg libraries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://x.org

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	libICE-1.0.10-8.el9 \
		libSM-1.2.3-10.el9 \
		libX11-1.7.0-8.el9 \
		libX11-xcb-1.7.0-8.el9 \
		libXScrnSaver-1.2.3-10.el9 \
		libXau-1.0.9-8.el9 \
		libXaw-1.0.13-19.el9 \
		libXcomposite-0.4.5-7.el9 \
		libXcursor-1.2.0-7.el9 \
		libXdamage-1.1.5-7.el9 \
		libXdmcp-1.1.3-8.el9 \
		libXext-1.3.4-8.el9 \
		libXfixes-5.0.3-16.el9 \
		libXfont2-2.0.3-12.el9 \
		libXft-2.3.3-8.el9 \
		libXi-1.7.10-8.el9 \
		libXinerama-1.1.4-10.el9 \
		libXmu-1.1.3-8.el9 \
		libXp-1.0.3-11.el9 \
		libXpm-3.5.13-8.el9_1 \
		libXrandr-1.5.2-8.el9 \
		libXrender-0.9.10-16.el9 \
		libXres-1.2.0-14.el9 \
		libXt-1.2.0-6.el9 \
		libXtst-1.2.3-16.el9 \
		libXv-1.0.11-16.el9 \
		libXxf86dga-1.1.5-8.el9 \
		libXxf86vm-1.1.4-18.el9 \
		libfontenc-1.1.3-17.el9 \
		libxcb-1.13.1-9.el9 \
		libxkbfile-1.1.0-8.el9 \
		libxshmfence-1.3-10.el9
SHARE_DISTNAMES=libX11-common-1.7.0-8.el9 \
		xkeyboard-config-2.33-2.el9
SRC_DISTFILES=	libICE-1.0.10-8.el9${SRC_SUFX}:SOURCE \
		libSM-1.2.3-10.el9${SRC_SUFX}:SOURCE \
		libX11-1.7.0-8.el9${SRC_SUFX}:SOURCE \
		libXScrnSaver-1.2.3-10.el9${SRC_SUFX}:SOURCE \
		libXau-1.0.9-8.el9${SRC_SUFX}:SOURCE \
		libXaw-1.0.13-19.el9${SRC_SUFX}:SOURCE \
		libXcomposite-0.4.5-7.el9${SRC_SUFX}:SOURCE \
		libXcursor-1.2.0-7.el9${SRC_SUFX}:SOURCE \
		libXdamage-1.1.5-7.el9${SRC_SUFX}:SOURCE \
		libXdmcp-1.1.3-8.el9${SRC_SUFX}:SOURCE \
		libXext-1.3.4-8.el9${SRC_SUFX}:SOURCE \
		libXfixes-5.0.3-16.el9${SRC_SUFX}:SOURCE \
		libXfont2-2.0.3-12.el9${SRC_SUFX}:SOURCE \
		libXft-2.3.3-8.el9${SRC_SUFX}:SOURCE \
		libXi-1.7.10-8.el9${SRC_SUFX}:SOURCE \
		libXinerama-1.1.4-10.el9${SRC_SUFX}:SOURCE \
		libXmu-1.1.3-8.el9${SRC_SUFX}:SOURCE \
		libXp-1.0.3-11.el9${SRC_SUFX}:SOURCE \
		libXpm-3.5.13-8.el9_1${SRC_SUFX}:SOURCE \
		libXrandr-1.5.2-8.el9${SRC_SUFX}:SOURCE \
		libXrender-0.9.10-16.el9${SRC_SUFX}:SOURCE \
		libXres-1.2.0-14.el9${SRC_SUFX}:SOURCE \
		libXt-1.2.0-6.el9${SRC_SUFX}:SOURCE \
		libXtst-1.2.3-16.el9${SRC_SUFX}:SOURCE \
		libXv-1.0.11-16.el9${SRC_SUFX}:SOURCE \
		libXxf86dga-1.1.5-8.el9${SRC_SUFX}:SOURCE \
		libXxf86vm-1.1.4-18.el9${SRC_SUFX}:SOURCE \
		libfontenc-1.1.3-17.el9${SRC_SUFX}:SOURCE \
		libxcb-1.13.1-9.el9${SRC_SUFX}:SOURCE \
		libxkbfile-1.1.0-8.el9${SRC_SUFX}:SOURCE \
		libxshmfence-1.3-10.el9${SRC_SUFX}:SOURCE \
		xkeyboard-config-2.33-2.el9${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${RM} -r ${WRKSRC}/usr/share/icons

.include <bsd.port.mk>
