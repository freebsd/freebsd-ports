PORTNAME=	xorg-libs
PORTVERSION=	7.7
PORTREVISION=	4
CATEGORIES=	x11 linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Xorg libraries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://x.org

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig python3 systemd-libs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

.include	"${.CURDIR}/Makefile.version"

LIB_DISTNAMES=	libICE-${libICE_ver} \
		libSM-${libSM_ver} \
		libX11-${libX11_ver} \
		libX11-xcb-${libX11_ver} \
		libXScrnSaver-${libXScrnSaver_ver} \
		libXau-${libXau_ver} \
		libXaw-${libXaw_ver} \
		libXcomposite-${libXcomposite_ver} \
		libXcursor-${libXcursor_ver} \
		libXdamage-${libXdamage_ver} \
		libXdmcp-${libXdmcp_ver} \
		libXext-${libXext_ver} \
		libXfixes-${libXfixes_ver} \
		libXfont2-${libXfont2_ver} \
		libXft-${libXft_ver} \
		libXi-${libXi_ver} \
		libXinerama-${libXinerama_ver} \
		libXmu-${libXmu_ver} \
		libXp-${libXp_ver} \
		libXpm-${libXpm_ver} \
		libXrandr-${libXrandr_ver} \
		libXrender-${libXrender_ver} \
		libXres-${libXres_ver} \
		libXt-${libXt_ver} \
		libXtst-${libXtst_ver} \
		libXv-${libXv_ver} \
		libXxf86dga-${libXxf86dga_ver} \
		libXxf86vm-${libXxf86vm_ver} \
		libfontenc-${libfontenc_ver} \
		libinput-${libinput_ver} \
		libwacom-${libwacom_ver} \
		libxcb-${libxcb_ver} \
		libxkbfile-${libxkbfile_ver} \
		libxshmfence-${libxshmfence_ver}
SHARE_DISTNAMES=libX11-common-${libX11_ver} \
		libwacom-data-${libwacom_ver} \
		xkeyboard-config-${xkeyboard-config_ver}
SRC_DISTFILES=	libICE-${libICE_ver}${SRC_SUFX}:SOURCE \
		libSM-${libSM_ver}${SRC_SUFX}:SOURCE \
		libX11-${libX11_ver}${SRC_SUFX}:SOURCE \
		libXScrnSaver-${libXScrnSaver_ver}${SRC_SUFX}:SOURCE \
		libXau-${libXau_ver}${SRC_SUFX}:SOURCE \
		libXaw-${libXaw_ver}${SRC_SUFX}:SOURCE \
		libXcomposite-${libXcomposite_ver}${SRC_SUFX}:SOURCE \
		libXcursor-${libXcursor_ver}${SRC_SUFX}:SOURCE \
		libXdamage-${libXdamage_ver}${SRC_SUFX}:SOURCE \
		libXdmcp-${libXdmcp_ver}${SRC_SUFX}:SOURCE \
		libXext-${libXext_ver}${SRC_SUFX}:SOURCE \
		libXfixes-${libXfixes_ver}${SRC_SUFX}:SOURCE \
		libXfont2-${libXfont2_ver}${SRC_SUFX}:SOURCE \
		libXft-${libXft_ver}${SRC_SUFX}:SOURCE \
		libXi-${libXi_ver}${SRC_SUFX}:SOURCE \
		libXinerama-${libXinerama_ver}${SRC_SUFX}:SOURCE \
		libXmu-${libXmu_ver}${SRC_SUFX}:SOURCE \
		libXp-${libXp_ver}${SRC_SUFX}:SOURCE \
		libXpm-${libXpm_ver}${SRC_SUFX}:SOURCE \
		libXrandr-${libXrandr_ver}${SRC_SUFX}:SOURCE \
		libXrender-${libXrender_ver}${SRC_SUFX}:SOURCE \
		libXres-${libXres_ver}${SRC_SUFX}:SOURCE \
		libXt-${libXt_ver}${SRC_SUFX}:SOURCE \
		libXtst-${libXtst_ver}${SRC_SUFX}:SOURCE \
		libXv-${libXv_ver}${SRC_SUFX}:SOURCE \
		libXxf86dga-${libXxf86dga_ver}${SRC_SUFX}:SOURCE \
		libXxf86vm-${libXxf86vm_ver}${SRC_SUFX}:SOURCE \
		libfontenc-${libfontenc_ver}${SRC_SUFX}:SOURCE \
		libinput-${libinput_ver}${SRC_SUFX}:SOURCE \
		libwacom-${libwacom_ver}${SRC_SUFX}:SOURCE \
		libxcb-${libxcb_ver}${SRC_SUFX}:SOURCE \
		libxkbfile-${libxkbfile_ver}${SRC_SUFX}:SOURCE \
		libxshmfence-${libxshmfence_ver}${SRC_SUFX}:SOURCE \
		xkeyboard-config-${xkeyboard-config_ver}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${RM} -r ${WRKSRC}/usr/share/icons

.include <bsd.port.mk>
