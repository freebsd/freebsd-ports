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

USE_X_PREFIX=	yes
NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel
INSTALLS_SHLIB=	yes

NVVERSION=	6113

.include <bsd.port.pre.mk>

# XXX Should use ${PKG_INFO} XXX
#
XSERVVERSION!=	/usr/sbin/pkg_info -O x11-servers/XFree86-4-Server 2>/dev/null | ${GREP} Server- || /usr/sbin/pkg_info -O x11-servers/xorg-server 2>/dev/null | ${GREP} server- || true
XLIBVERSION!=	/usr/sbin/pkg_info -O x11/XFree86-4-libraries 2>/dev/null | ${GREP} libraries- || /usr/sbin/pkg_info -O x11/xorg-libraries 2>/dev/null | ${GREP} libraries- || true

PLIST_SUB=	XSERVVERSION=${XSERVVERSION} XLIBVERSION=${XLIBVERSION} \
		LINUXBASE=${LINUXBASE} NVVERSION=${NVVERSION}

.if !defined(WITHOUT_LINUX)
USE_LINUX=	yes
PLIST_SUB+=	LINUX=""
.else
PLIST_SUB+=	LINUX="@comment "
.endif

.if ${OSVERSION} < 490000 || (${OSVERSION} >= 500000 && ${OSVERSION} < 502001)
IGNORE=		"supports FreeBSD -STABLE (4.9 or later), or FreeBSD -CURRENT (5.2.1 or later)"
.endif

.if ${OSVERSION} < 500000
PLIST_SUB+=	FREEBSD5="@comment " FREEBSD4=""
.else
PLIST_SUB+=	FREEBSD5="" FREEBSD4="@comment "
.endif

pre-everything::
.if !defined(WITH_FREEBSD_AGP)
	@${ECHO_MSG} "Define WITH_FREEBSD_AGP to use FreeBSD AGP GART driver"
.endif
.if !defined(WITH_VM86_INT10CALL)
	@${ECHO_MSG} "Define WITH_VM86_INT10CALL to use VM86 interface for INT10 calls (video BIOS)"
.endif
.if !defined(WITH_ACPI)
	@${ECHO_MSG} "Define WITH_ACPI to enable support for ACPI Power Management (5.X only!)"
.endif
.if !defined(WITHOUT_LINUX)
	@${ECHO_MSG} "Define WITHOUT_LINUX to build without support for Linux compatibility"
.endif

.if defined(WITH_FREEBSD_AGP) || defined(WITH_VM86_INT10CALL) || defined(WITH_ACPI) || defined(WITHOUT_LINUX)
USE_REINPLACE=	yes

post-patch:
. if defined(WITH_FREEBSD_AGP)
	@${REINPLACE_CMD} 's/undef NV_SUPPORT_OS_AGP/define NV_SUPPORT_OS_AGP/' \
		${WRKSRC}/src/nv-freebsd.h
. endif
. if defined(WITH_VM86_INT10CALL)
	@${REINPLACE_CMD} 's/undef NV_USE_OS_VM86_INT10CALL/define NV_USE_OS_VM86_INT10CALL/' \
		${WRKSRC}/src/nv-freebsd.h
. endif
. if defined(WITH_ACPI)
	@${REINPLACE_CMD} 's/undef NV_SUPPORT_ACPI_PM/define NV_SUPPORT_ACPI_PM/' \
		${WRKSRC}/src/nv-freebsd.h
. endif
. if defined(WITHOUT_LINUX)
	@${REINPLACE_CMD} 's/define NV_SUPPORT_LINUX_COMPAT/undef NV_SUPPORT_LINUX_COMPAT/' \
		${WRKSRC}/src/nv-freebsd.h
. endif
.endif

post-install:
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
