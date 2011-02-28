# New ports collection makefile for:	x11/linux-f8-xorg-libs
# Date created:				2008-03-29
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=		xorg-libs
PORTVERSION=		7.3
PORTREVISION=		3
CATEGORIES=		x11 linux
PKGNAMEPREFIX=		linux-f8-
DISTFILES=	libICE-1.0.4-2.fc8.${LINUX_RPM_ARCH}.rpm \
		libFS-1.0.0-6.fc8.${LINUX_RPM_ARCH}.rpm \
		libSM-1.0.2-4.fc8.${LINUX_RPM_ARCH}.rpm \
		libX11-1.1.3-4.fc8.${LINUX_RPM_ARCH}.rpm \
		libXScrnSaver-1.1.2-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXTrap-1.0.0-4.fc8.${LINUX_RPM_ARCH}.rpm \
		libXau-1.0.3-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXaw-1.0.4-1.fc8.${LINUX_RPM_ARCH}.rpm \
		libXcomposite-0.4.0-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXcursor-1.1.9-1.fc8.${LINUX_RPM_ARCH}.rpm \
		libXdamage-1.1.1-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXdmcp-1.0.2-4.fc8.${LINUX_RPM_ARCH}.rpm \
		libXevie-1.0.2-2.fc8.${LINUX_RPM_ARCH}.rpm \
		libXext-1.0.1-4.fc8.${LINUX_RPM_ARCH}.rpm \
		libXfixes-4.0.3-2.fc8.${LINUX_RPM_ARCH}.rpm \
		libXfont-1.3.1-2.fc8.${LINUX_RPM_ARCH}.rpm \
		libXft-2.1.12-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXi-1.1.3-1.fc8.${LINUX_RPM_ARCH}.rpm \
		libXinerama-1.0.2-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXmu-1.0.3-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXp-1.0.0-8.fc8.${LINUX_RPM_ARCH}.rpm \
		libXpm-3.5.7-1.fc8.${LINUX_RPM_ARCH}.rpm \
		libXrandr-1.2.2-1.fc8.${LINUX_RPM_ARCH}.rpm \
		libXrender-0.9.4-1.fc8.${LINUX_RPM_ARCH}.rpm \
		libXt-1.0.4-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXtst-1.0.3-1.fc8.${LINUX_RPM_ARCH}.rpm \
		libXres-1.0.3-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXv-1.0.3-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXvMC-1.0.4-3.fc8.${LINUX_RPM_ARCH}.rpm \
		libXxf86dga-1.0.1-4.fc8.${LINUX_RPM_ARCH}.rpm \
		libXxf86misc-1.0.1-4.fc8.${LINUX_RPM_ARCH}.rpm \
		libXxf86vm-1.0.1-4.fc8.${LINUX_RPM_ARCH}.rpm \
		libfontenc-1.0.4-4.fc8.${LINUX_RPM_ARCH}.rpm \
		libxcb-1.1-1.1.fc8.${LINUX_RPM_ARCH}.rpm \
		libxkbfile-1.0.4-3.fc8.${LINUX_RPM_ARCH}.rpm \
		mesa-libGLw-6.5.1-4.fc8.${LINUX_RPM_ARCH}.rpm

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	libICE-1.0.4-2.fc8.src.rpm \
		libFS-1.0.0-6.fc8.src.rpm \
		libSM-1.0.2-4.fc8.src.rpm \
		libX11-1.1.3-4.fc8.src.rpm \
		libXScrnSaver-1.1.2-3.fc8.src.rpm \
		libXTrap-1.0.0-4.fc8.src.rpm \
		libXau-1.0.3-3.fc8.src.rpm \
		libXaw-1.0.4-1.fc8.src.rpm \
		libXcomposite-0.4.0-3.fc8.src.rpm \
		libXcursor-1.1.9-1.fc8.src.rpm \
		libXdamage-1.1.1-3.fc8.src.rpm \
		libXdmcp-1.0.2-4.fc8.src.rpm \
		libXevie-1.0.2-2.fc8.src.rpm \
		libXext-1.0.1-4.fc8.src.rpm \
		libXfixes-4.0.3-2.fc8.src.rpm \
		libXfont-1.3.1-2.fc8.src.rpm \
		libXft-2.1.12-3.fc8.src.rpm \
		libXi-1.1.3-1.fc8.src.rpm \
		libXinerama-1.0.2-3.fc8.src.rpm \
		libXmu-1.0.3-3.fc8.src.rpm \
		libXp-1.0.0-8.fc8.src.rpm \
		libXpm-3.5.7-1.fc8.src.rpm \
		libXrandr-1.2.2-1.fc8.src.rpm \
		libXrender-0.9.4-1.fc8.src.rpm \
		libXt-1.0.4-3.fc8.src.rpm \
		libXtst-1.0.3-1.fc8.src.rpm \
		libXres-1.0.3-3.fc8.src.rpm \
		libXv-1.0.3-3.fc8.src.rpm \
		libXvMC-1.0.4-3.fc8.src.rpm \
		libXxf86dga-1.0.1-4.fc8.src.rpm \
		libXxf86misc-1.0.1-4.fc8.src.rpm \
		libXxf86vm-1.0.1-4.fc8.src.rpm \
		libfontenc-1.0.4-4.fc8.src.rpm \
		libxcb-1.1-1.1.fc8.src.rpm \
		libxkbfile-1.0.4-3.fc8.src.rpm \
		mesa-libGLw-6.5.1-4.fc8.src.rpm

ALWAYS_KEEP_DISTFILES=	YES
.endif

CONFLICTS=		linux-xorg-libs-[0-9]* linux-f10-xorg-libs-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

MAINTAINER=		freebsd-emulation@FreeBSD.org
COMMENT=		Xorg libraries (Linux Fedora 8)

USE_LINUX_RPM=		yes
USE_LINUX_APPS=		fontconfig
LINUX_DIST_VER=		8
RPMVERSION=		4.fc8
USE_LDCONFIG=		yes

post-install:
	@${INSTALL_DATA} ${FILESDIR}/xorg-x11-i386.conf ${PREFIX}/etc/ld.so.conf.d

.include <bsd.port.mk>
