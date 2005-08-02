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
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	FREEBSD_AGP	"Use FreeBSD AGP GART driver" off \
		VM86_INT10CALL	"Use VM86 interface for video BIOS calls" off \
		ACPI		"Enable support for ACPI Power Management" off \
		LINUX		"Build with support for Linux compatibility" on

# Get __FreeBSD_version.  Needed to set PORTREVISION before including of
# <bsd.port.pre.mk>.
# XXX This is not required for -CURRENT XXX
#
.if !defined(OSVERSION)
.if exists(/sbin/sysctl)
OSVERSION!=	/sbin/sysctl -n kern.osreldate
.else
OSVERSION!=	/usr/sbin/sysctl -n kern.osreldate
.endif
.endif

# Newer releases from NVidia do not play nicely with FreeBSD prior to 5.3.
# While we support 4.x/5.2.1 releases, stick to version 6113 of driver for
# that old versions of FreeBSD.  This can go away when we stop supporting
# them.  For details, please refer to PR ports/79571.
#
# Starting with version 7667, NVidia has dropped support for numerous
# "legacy" GPUs.  One can, however, build the port with -DWITH_LEGACY_GPU_SUPPORT
# to go with version 7174 of driver (this does not apply to older versions
# of FreeBSD, since one has to use version 6113 of driver (if [s]he did not
# yet upgraded to FreeBSD 5.3 or later) which has support for those GPUs).
#
# If you must use WITH_LEGACY_GPU_SUPPORT option, be sure to ``hold'' the
# package by making appropriate entry in your pkgtools.conf, otherwise
# portupgrade(1) will upgrade your port to latest NVidia release on the
# next run, which is probably not what you want.
#
# 			ATTENTION!! ACHTUNG!! VNIMANIE!!
#
# This very Makefile is already overly complicated, thus support for
# multiple versions of NVidia releases is going away once we stop caring for
# ports on 4.x versions of FreeBSD.  This also applies to "legacy GPUs"
# support.  Those poor souls^W^Wproud owners of RIVA's and Vanta's, frankly,
# should consider buying a modern gfx card.
#
# XXX WITH_LEGACY_GPU_SUPPORT is not in OPTIONS because it has to be handled
# _before_ including of <bsd.port.pre.mk>.  On the other hand, it is really
# an UNSUPPORTED option anyway, so this is for good to hide it here XXX
#
.if ${OSVERSION} < 503000
NVVERSION=	6113
PORTREVISION=	4
PLIST_SUB+=	DIFFS="" DRVSO="@comment "
EXTRA_PATCHES+=	${FILESDIR}/${NVVERSION}-*
.else
.if defined(WITH_LEGACY_GPU_SUPPORT)
NVVERSION=	7174
PORTREVISION=	1
EXTRA_PATCHES+=	${FILESDIR}/6113-patch-lib::Makefile
.else
NVVERSION=	7667
EXTRA_PATCHES+=	${FILESDIR}/${NVVERSION}-*
.endif
PLIST_SUB+=	DIFFS="@comment " DRVSO=""
.endif

.include <bsd.port.pre.mk>

# XXX Should use ${PKG_INFO} XXX
#
XSERVVERSION!=	/usr/sbin/pkg_info -O x11-servers/XFree86-4-Server 2>/dev/null | ${GREP} Server- || /usr/sbin/pkg_info -O x11-servers/xorg-server 2>/dev/null | ${GREP} server- || true
XLIBVERSION!=	/usr/sbin/pkg_info -O x11/XFree86-4-libraries 2>/dev/null | ${GREP} libraries- || /usr/sbin/pkg_info -O x11/xorg-libraries 2>/dev/null | ${GREP} libraries- || true

PLIST_SUB+=	XSERVVERSION=${XSERVVERSION} XLIBVERSION=${XLIBVERSION} \
		LINUXBASE=${LINUXBASE} NVVERSION=${NVVERSION}

.if !defined(WITHOUT_LINUX)
USE_LINUX=	yes
USE_XLIB=	yes
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
.if ${NVVERSION} >= 7174
	${REINPLACE_CMD} '24,26d' ${WRKSRC}/src/nv-freebsd.h
.endif
.if ${OSVERSION} > 600028
	${REINPLACE_CMD} '/bus_memio\.h/d' ${WRKSRC}/src/nv-freebsd.h
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
