# New ports collection makefile for:	nvidia-driver
# Date created:				4 December 2002
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	nvidia-driver
PORTVERSION=	1.0.${NVVERSION}
CATEGORIES=	x11
MASTER_SITES=	http://us.download.nvidia.com/freebsd/1.0-${NVVERSION}/ \
		ftp://download.nvidia.com/freebsd/1.0-${NVVERSION}/ \
		http://download1.nvidia.com/freebsd/1.0-${NVVERSION}/ \
		ftp://download1.nvidia.com/freebsd/1.0-${NVVERSION}/
DISTNAME=	NVIDIA-FreeBSD-x86-${PORTVERSION:S/0./0-/}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering

ONLY_FOR_ARCHS=	i386

USE_X_PREFIX=	yes
NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel
INSTALLS_SHLIB=	yes
SUB_FILES+=	pkg-message
DOCSDIR=	${PREFIX}/share/doc/NVIDIA_GLX-1.0

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

# Starting with version 7667, NVidia has dropped support for numerous
# "legacy" GPUs.  One can, however, build the port with -DWITH_LEGACY_GPU_SUPPORT
# to go with version 7184 of the driver.
#
# If you must use WITH_LEGACY_GPU_SUPPORT option, be sure to ``hold'' the
# package by making appropriate entry in your pkgtools.conf, otherwise
# portupgrade(1) will upgrade your port to latest NVidia release on the
# next run, which is probably not what you want.
#
# Please be aware that legacy GPUs support is probably going away in some
# near future (once nVidia itself cancels support of those).  Those poor
# souls^W^Wproud owners of RIVA's and Vanta's, frankly, should consider
# buying a modern gfx card.
#
# XXX WITH_LEGACY_GPU_SUPPORT is not in OPTIONS because it has to be handled
# _before_ including of <bsd.port.pre.mk>.  On the other hand, it is really
# an UNSUPPORTED option anyway, so this is for good to hide it here XXX
#
.if defined(WITH_LEGACY_GPU_SUPPORT)
NVVERSION=	7184
EXTRA_PATCHES+=	${FILESDIR}/6113-patch-lib::Makefile
.else
NVVERSION=	9631
EXTRA_PATCHES+=	${FILESDIR}/7667-*
.endif
.if ${OSVERSION} >= 600033
LIB_DEPENDS+=	m.3:${PORTSDIR}/misc/compat5x
.endif

.include <bsd.port.pre.mk>

# XXX Should use ${PKG_INFO} XXX
#
XSERVVERSION!=	/usr/sbin/pkg_info -O x11-servers/XFree86-4-Server 2>/dev/null | ${GREP} Server- || /usr/sbin/pkg_info -O x11-servers/xorg-server 2>/dev/null | ${GREP} server- || true
XLIBVERSION!=	/usr/sbin/pkg_info -O x11/XFree86-4-libraries 2>/dev/null | ${GREP} libraries- || /usr/sbin/pkg_info -O x11/xorg-libraries 2>/dev/null | ${GREP} libraries- || true

PLIST_SUB+=	XSERVVERSION=${XSERVVERSION} XLIBVERSION=${XLIBVERSION} \
		LINUXBASE=${LINUXBASE} NVVERSION=${NVVERSION}

.if !defined(WITHOUT_LINUX)
# Add explicit X11 libraries dependency since USE_LINUX causes the port to
# RUN_DEPEND on the Linux libraries rather than LIB_DEPEND on native ones
LIB_DEPENDS+=	X11.6:${X_LIBRARIES_PORT}
USE_LINUX=	yes
PLIST_SUB+=	LINUX=""
.else
PLIST_SUB+=	LINUX="@comment "
.endif

.if ${OSVERSION} < 503000
IGNORE=		supports FreeBSD-STABLE (5.3 or later), or FreeBSD-CURRENT
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
	${REINPLACE_CMD} -E 's/undef (NV_SUPPORT_OS_AGP)/define \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(WITH_VM86_INT10CALL)
	${REINPLACE_CMD} -E 's/undef (NV_USE_OS_VM86_INT10CALL)/define \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(WITH_ACPI)
	${REINPLACE_CMD} -E 's/undef (NV_SUPPORT_ACPI_PM)/define \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(WITHOUT_LINUX)
	${REINPLACE_CMD} -E 's/define (NV_SUPPORT_LINUX_COMPAT)/undef \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
	${REINPLACE_CMD} -E 's/(extension).*/\1/ ; /bin/d ; /man/d' \
		${WRKSRC}/x11/Makefile

post-install:
# pkg-plist is already overbloated, so use this hack instead of PLIST_SUB's
.if ${NVVERSION} < 8174
	@${REINPLACE_CMD} '/libnvidia-cfg/d ; /html/d' ${TMPPLIST}
.else
	@${REINPLACE_CMD} '/README\.Linux/d' ${TMPPLIST}
.endif
	${LN} -sf libXvMCNVIDIA.so.1 ${PREFIX}/lib/libXvMCNVIDIA_dynamic.so.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
