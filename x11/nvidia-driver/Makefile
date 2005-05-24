# New ports collection makefile for:	nvidia-driver
# Date created:				4 December 2002
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	nvidia-driver
PORTVERSION=	1.0.${NVVERSION}
CATEGORIES=	x11
MASTER_SITES=	http://download.nvidia.com/freebsd/1.0-${NVVERSION}/ \
		ftp://download.nvidia.com/freebsd/1.0-${NVVERSION}/ \
		http://download1.nvidia.com/freebsd/1.0-${NVVERSION}/ \
		ftp://download1.nvidia.com/freebsd/1.0-${NVVERSION}/
DISTNAME=	NVIDIA-FreeBSD-x86-${PORTVERSION:S/0./0-/}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering

ONLY_FOR_ARCHS=	i386

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel
INSTALLS_SHLIB=	yes

OPTIONS=	FREEBSD_AGP	"Use FreeBSD AGP GART driver" off \
		VM86_INT10CALL	"Use VM86 interface for video BIOS calls" off \
		ACPI		"Enable support for ACPI Power Management" off \
		LINUX		"Build with support for Linux compatibility" on

.include <bsd.port.pre.mk>

# Newer releases from NVidia do not play nicely with FreeBSD prior to 5.3.
# While we support 4.x/5.2.1 releases, stick to 6113 version of driver for
# that old versions of FreeBSD.  This can go away when we stop supporting
# them.  For details, please refer to PR ports/79571.
#
.if ${OSVERSION} < 503000
NVVERSION=	6113
PORTREVISION=	4
EXTRA_PATCHES+=	${FILESDIR}/6113-patch-src::nvidia_pci.c
PLIST_SUB+=	DIFFS=""
.else
NVVERSION=	7174
PLIST_SUB+=	DIFFS="@comment "
.endif

# XXX Should use ${PKG_INFO} XXX
#
XSERVVERSION!=	/usr/sbin/pkg_info -O x11-servers/XFree86-4-Server 2>/dev/null | ${GREP} Server- || /usr/sbin/pkg_info -O x11-servers/xorg-server 2>/dev/null | ${GREP} server- || true
XLIBVERSION!=	/usr/sbin/pkg_info -O x11/XFree86-4-libraries 2>/dev/null | ${GREP} libraries- || /usr/sbin/pkg_info -O x11/xorg-libraries 2>/dev/null | ${GREP} libraries- || true

PLIST_SUB+=	XSERVVERSION=${XSERVVERSION} XLIBVERSION=${XLIBVERSION} \
		LINUXBASE=${LINUXBASE} NVVERSION=${NVVERSION}

.if !defined(WITHOUT_LINUX)
USE_LINUX?=	yes
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libXrender.so.1:${PORTSDIR}/x11/linux-XFree86-libs
PLIST_SUB+=	LINUX=""
.else
PLIST_SUB+=	LINUX="@comment "
.endif

.if ${OSVERSION} < 490000 || ${OSVERSION} >= 500000 && ${OSVERSION} < 502001
IGNORE=		supports FreeBSD -STABLE (4.9 or later, 5.2.1 or later), or FreeBSD -CURRENT
.endif

.if ${OSVERSION} < 500000
PLIST_SUB+=	FREEBSD5="@comment " FREEBSD4=""
.else
PLIST_SUB+=	FREEBSD5="" FREEBSD4="@comment "
.endif

post-patch: .SILENT
# We should support -CURRENT: kill the check
.if ${NVVERSION} == 7174
	${REINPLACE_CMD} '24,26d' ${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(WITH_FREEBSD_AGP)
	${REINPLACE_CMD} 's/undef NV_SUPPORT_OS_AGP/define NV_SUPPORT_OS_AGP/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(WITH_VM86_INT10CALL)
	${REINPLACE_CMD} 's/undef NV_USE_OS_VM86_INT10CALL/define NV_USE_OS_VM86_INT10CALL/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(WITH_ACPI)
	${REINPLACE_CMD} 's/undef NV_SUPPORT_ACPI_PM/define NV_SUPPORT_ACPI_PM/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(WITHOUT_LINUX)
	${REINPLACE_CMD} 's/define NV_SUPPORT_LINUX_COMPAT/undef NV_SUPPORT_LINUX_COMPAT/' \
		${WRKSRC}/src/nv-freebsd.h
.endif

post-install:
	${LN} -sf libXvMCNVIDIA.so.1 ${PREFIX}/lib/libXvMCNVIDIA_dynamic.so.1
.if ${OSVERSION} < 500000
.for dev in 0 1 2 3
	@${RM} -f /dev/nvidia${dev}
	@mknod /dev/nvidia${dev} c 180 ${dev}
	@${CHMOD} 0666 /dev/nvidia${dev}
.endfor
	@${RM} -f /dev/nvidiactl
	@mknod /dev/nvidiactl c 180 255
	@${CHMOD} 0666 /dev/nvidiactl
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
