# Created by: Vassilis based on f10 from bsam
# $FreeBSD$

PORTNAME=	xorg-libs
PORTVERSION=	1
CATEGORIES=		x11 linux
MASTER_SITES=		http://archives.fedoraproject.org/pub/fedora/linux/releases/${LINUX_RPM_VERSION}/Everything/${LINUX_CPU_ARCH}/os/Packages/
PKGNAMEPREFIX=	linux-f20-
DISTFILES=	${BIN_DISTFILES}
EXTRACT_ONLY=		${DISTFILES} ${DISTFILES_DEPS}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		Xorg libraries (Linux Fedora 20)

BIN_DISTFILES=	\
		l/libICE-1.0.8-6.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libFS-1.0.5-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libSM-1.2.1-6.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libX11-1.6.1-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libX11-common-1.6.1-1.fc${LINUX_RPM_VERSION}.noarch.rpm \
		l/libXNVCtrl-169.12-9.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXScrnSaver-1.2.2-6.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXau-1.0.8-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXaw-1.0.11-6.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXaw3dXft-1.6.2b-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXcm-0.5.1-4.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXcomp-3.5.0.21-3.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXcompext-3.5.0.21-3.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXcomposite-0.4.4-4.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXcompshad-3.5.0.21-3.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXcursor-1.1.14-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXdamage-1.1.4-4.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXdmcp-1.1.1-5.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXevie-1.0.3-7.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXext-1.3.2-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXfixes-5.0.1-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXfont-1.4.6-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXft-2.3.1-5.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXi-1.7.2-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXinerama-1.1.3-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXmu-1.1.1-5.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXp-1.0.2-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXpm-3.5.10-5.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXrandr-1.4.1-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXrender-0.9.8-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXres-1.0.7-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXt-1.1.4-7.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXtst-1.2.2-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXv-1.0.9-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXvMC-1.0.8-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXxf86dga-1.1.4-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXxf86misc-1.0.3-7.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libXxf86vm-1.1.3-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libfontenc-1.1.1-4.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libfonts-1.1.3-13.fc${LINUX_RPM_VERSION}.noarch.rpm \
		l/libxcb-1.9.1-3.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libxkbcommon-0.3.1-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
		l/libxkbfile-1.0.8-4.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm

		# m/mesa-libGLw-8.0.0-3.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \

# This probably should be in the USE_LINUX_APPS; waiting for modular support of linux_base
# of the user's choice in /usr/ports/Mk/bsd.linux-apps.mk
DISTFILES_DEPS=	\
		f/fontconfig-2.11.0-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm

ONLY_FOR_ARCHS=	i386 amd64
LINUX_CPU_ARCH=		i386
LINUX_RPM_ARCH=		i686
LINUX_RPM_VERSION=	20
USE_LINUX_PREFIX=	yes
USE_LINUX=			f20
NO_WRKSUBDIR=		yes
DISTINFO_FILE?=		${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

CONFLICTS=		linux-xorg-libs-[0-9]* linux-f8-xorg-libs-[0-9]* linux-f10-xorg-libs-[0-9]*

EXTRACT_CMD?=		${TAR}
EXTRACT_BEFORE_ARGS?=	-xPf
EXTRACT_AFTER_ARGS?=

do-build:

do-install:
	@cd ${WRKSRC} && ${FIND} * ! -path "stage*" -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/{}" \;
	@cd ${WRKSRC} && ${FIND} * ! -path "stage/*" ! -type d \
		| ${CPIO} -pm -R root:wheel ${STAGEDIR}${PREFIX}

#USE_LINUX_APPS=		fontconfig
USE_LDCONFIG=		yes

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ld.so.conf.d
	@${INSTALL_DATA} ${FILESDIR}/xorg-x11-i386.conf ${STAGEDIR}${PREFIX}/etc/ld.so.conf.d

.include <bsd.port.mk>
