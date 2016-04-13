# Created by: bsam
# $FreeBSD$

PORTNAME=	xorg-libs
PORTVERSION=	7.4
PORTREVISION=	4
CATEGORIES=	x11 linux
MASTER_SITES=	CENTOS_LINUX CENTOS_LINUX_UPDATES
DISTFILES:=	#hack
LIB_DISTFILES=	libICE-1.0.6-1.el6.${LINUX_RPM_ARCH}.rpm \
		libSM-1.2.1-2.el6.${LINUX_RPM_ARCH}.rpm \
		libX11-1.6.0-6.el6.${LINUX_RPM_ARCH}.rpm \
		libXScrnSaver-1.2.2-2.el6.${LINUX_RPM_ARCH}.rpm \
		libXau-1.0.6-4.el6.${LINUX_RPM_ARCH}.rpm \
		libXaw-1.0.11-2.el6.${LINUX_RPM_ARCH}.rpm \
		libXcomposite-0.4.3-4.el6.${LINUX_RPM_ARCH}.rpm \
		libXcursor-1.1.14-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXdamage-1.1.3-4.el6.${LINUX_RPM_ARCH}.rpm \
		libXdmcp-1.1.1-3.el6.${LINUX_RPM_ARCH}.rpm \
		libXevie-1.0.3-4.el6.${LINUX_RPM_ARCH}.rpm \
		libXext-1.3.2-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXfixes-5.0.1-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXfont-1.4.5-5.el6_7.${LINUX_RPM_ARCH}.rpm \
		libXft-2.3.1-2.el6.${LINUX_RPM_ARCH}.rpm \
		libXi-1.7.2-2.2.el6.${LINUX_RPM_ARCH}.rpm \
		libXinerama-1.1.3-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXmu-1.1.1-2.el6.${LINUX_RPM_ARCH}.rpm \
		libXp-1.0.2-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXpm-3.5.10-2.el6.${LINUX_RPM_ARCH}.rpm \
		libXrandr-1.4.1-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXrender-0.9.8-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXres-1.0.7-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXt-1.1.4-6.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXtst-1.2.2-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXv-1.0.9-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXvMC-1.0.8-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXxf86dga-1.1.4-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libXxf86misc-1.0.3-4.el6.${LINUX_RPM_ARCH}.rpm \
		libXxf86vm-1.1.3-2.1.el6.${LINUX_RPM_ARCH}.rpm \
		libfontenc-1.0.5-2.el6.${LINUX_RPM_ARCH}.rpm \
		libxcb-1.9.1-3.el6.${LINUX_RPM_ARCH}.rpm \
		libxkbfile-1.0.6-1.1.el6.${LINUX_RPM_ARCH}.rpm \
		mesa-libGLw-6.5.1-10.el6.${LINUX_RPM_ARCH}.rpm

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	libICE-1.0.6-1.el6.src.rpm:SOURCE \
		libSM-1.2.1-2.el6.src.rpm:SOURCE \
		libX11-1.6.0-6.el6.src.rpm:SOURCE \
		libXScrnSaver-1.2.2-2.el6.src.rpm:SOURCE \
		libXau-1.0.6-4.el6.src.rpm:SOURCE \
		libXaw-1.0.11-2.el6.src.rpm:SOURCE \
		libXcomposite-0.4.3-4.el6.src.rpm:SOURCE \
		libXcursor-1.1.14-2.1.el6.src.rpm:SOURCE \
		libXdamage-1.1.3-4.el6.src.rpm:SOURCE \
		libXdmcp-1.1.1-3.el6.src.rpm:SOURCE \
		libXevie-1.0.3-4.el6.src.rpm:SOURCE \
		libXext-1.3.2-2.1.el6.src.rpm:SOURCE \
		libXfixes-5.0.1-2.1.el6.src.rpm:SOURCE \
		libXfont-1.4.5-5.el6_7.src.rpm:SOURCE \
		libXft-2.3.1-2.el6.src.rpm:SOURCE \
		libXi-1.7.2-2.2.el6.src.rpm:SOURCE \
		libXinerama-1.1.3-2.1.el6.src.rpm:SOURCE \
		libXmu-1.1.1-2.el6.src.rpm:SOURCE \
		libXp-1.0.2-2.1.el6.src.rpm:SOURCE \
		libXpm-3.5.10-2.el6.src.rpm:SOURCE \
		libXrandr-1.4.1-2.1.el6.src.rpm:SOURCE \
		libXrender-0.9.8-2.1.el6.src.rpm:SOURCE \
		libXres-1.0.7-2.1.el6.src.rpm:SOURCE \
		libXt-1.1.4-6.1.el6.src.rpm:SOURCE \
		libXtst-1.2.2-2.1.el6.src.rpm:SOURCE \
		libXv-1.0.9-2.1.el6.src.rpm:SOURCE \
		libXvMC-1.0.8-2.1.el6.src.rpm:SOURCE \
		libXxf86dga-1.1.4-2.1.el6.src.rpm:SOURCE \
		libXxf86misc-1.0.3-4.el6.src.rpm:SOURCE \
		libXxf86vm-1.1.3-2.1.el6.src.rpm:SOURCE \
		libfontenc-1.0.5-2.el6.src.rpm:SOURCE \
		libxcb-1.9.1-3.el6.src.rpm:SOURCE \
		libxkbfile-1.0.6-1.1.el6.src.rpm:SOURCE \
		mesa-libGLw-6.5.1-10.el6.src.rpm:SOURCE
.endif

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		Xorg libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=		linux-xorg-libs-[0-9]* linux-f8-xorg-libs-[0-9]* linux-f10-xorg-libs-[0-9]*

USE_LINUX=	c6
USE_LINUX_APPS=		fontconfig
USE_LINUX_RPM=		yes
USE_LDCONFIG=		yes

#post-install:
#	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ld.so.conf.d
#	@${INSTALL_DATA} ${FILESDIR}/xorg-x11-i386.conf ${STAGEDIR}${PREFIX}/etc/ld.so.conf.d

.include <bsd.port.mk>
