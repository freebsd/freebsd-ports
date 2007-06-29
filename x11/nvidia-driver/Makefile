# New ports collection makefile for:	nvidia-driver
# Date created:				4 December 2002
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	nvidia-driver
PORTVERSION=	1.0.${NVVERSION}
PORTREVISION=	5
CATEGORIES=	x11 kld
MASTER_SITES=	${MASTER_SITE_NVIDIA}
MASTER_SITE_SUBDIR=	freebsd/1.0-${NVVERSION}
DISTNAME=	NVIDIA-FreeBSD-x86-${PORTVERSION:S/0./0-/}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering

ONLY_FOR_ARCHS=	i386

USE_X_PREFIX=	yes
NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel
USE_GL=		gl
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
# "legacy" GPUs.  One can, however, build the port with specific NVVERSION
# value set.  Currently supported "legacy" values are 7184 and 9631.
# Consult NVidia README (Appendix A) to find out whether you need to use
# legacy driver version.  Alternatively, you can install corresponding
# `x11/nvidia-driver-XXXX' slave port, where XXXX == needed ${NVVERSION}.
#
NVVERSION?=	9746			# The latest version to date

.if ${NVVERSION} == 7184
EXTRA_PATCHES+=	${FILESDIR}/6113-patch-lib::Makefile
.else
EXTRA_PATCHES+=	${FILESDIR}/7667-* \
		${FILESDIR}/crash-patch-by-zander-1759235
.endif

.if ${OSVERSION} >= 600033
LIB_DEPENDS+=	m.3:${PORTSDIR}/misc/compat5x
.endif

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM} == "xorg"
MODULESDIR=	lib/xorg/modules
XORG_SUB=	"@comment "
XFREE86_SUB=	""
.else
MODULESDIR=	lib/modules
XORG_SUB=	""
XFREE86_SUB=	"@comment "
.endif

# XXX Should use ${PKG_INFO} XXX
#
XSERVVERSION!=	/usr/sbin/pkg_info -O x11-servers/XFree86-4-Server 2>/dev/null | ${GREP} Server- || /usr/sbin/pkg_info -O x11-servers/xorg-server 2>/dev/null | ${GREP} server- || true
XLIBVERSION!=	/usr/sbin/pkg_info -O x11/XFree86-4-libraries 2>/dev/null | ${GREP} libraries- || /usr/sbin/pkg_info -O graphics/libGL 2>/dev/null | ${GREP} libGL- || true

PLIST_SUB+=	XSERVVERSION=${XSERVVERSION} XLIBVERSION=${XLIBVERSION} \
		LINUXBASE=${LINUXBASE} NVVERSION=${NVVERSION} \
		MODULESDIR=${MODULESDIR} XORG=${XORG_SUB} XFREE86=${XFREE86_SUB}

.if !defined(WITHOUT_LINUX)
# Add explicit X11 libraries dependency since USE_LINUX causes the port to
# RUN_DEPEND on the Linux libraries rather than LIB_DEPEND on native ones
LIB_DEPENDS+=	X11.6:${X_LIBRARIES_PORT}
USE_LINUX=	yes
PLIST_SUB+=	LINUX=""
.else
PLIST_SUB+=	LINUX="@comment "
# Propagate WITHOUT_LINUX variable down to inner Makefiles
MAKE_ENV+=	WITHOUT_LINUX=yes
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
.if ${OSVERSION} > 700030
	${REINPLACE_CMD} -e 's/nvidia_intr/NULL, &/' ${WRKSRC}/src/nvidia_pci.c
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
.if ${NVVERSION} < 9746
	${REINPLACE_CMD} -E 's/(extension).*/\1/' ${WRKSRC}/x11/Makefile
.else
	${REINPLACE_CMD} -E 's/(lib).*/\1/' ${WRKSRC}/x11/Makefile
.endif
.if ${X_WINDOW_SYSTEM} == "xorg"
	${REINPLACE_CMD} -e 's|lib/modules|lib/xorg/modules|' \
		${WRKSRC}/x11/driver/Makefile \
		${WRKSRC}/x11/extension/Makefile
.if ${NVVERSION} >= 9746
	${REINPLACE_CMD} -e 's|lib/modules|lib/xorg/modules|' \
		${WRKSRC}/x11/lib/Makefile
.endif
.endif
	${REINPLACE_CMD} '/bin/d ; /man/d' ${WRKSRC}/x11/Makefile

pre-install:
	${MKDIR} ${PREFIX}/${MODULESDIR}/drivers

post-install:
# pkg-plist is already overbloated, so use this hack instead of PLIST_SUB's
.if ${NVVERSION} < 8174
	@${REINPLACE_CMD} '/libnvidia-cfg/d ; /html/d' ${TMPPLIST}
.else
	@${REINPLACE_CMD} '/README\.Linux/d ; /nvidia_drv\.o/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 9746
	@${REINPLACE_CMD} '/wfb/d ; /chapter-10/d' ${TMPPLIST}
.endif
	${LN} -sf libXvMCNVIDIA.so.1 ${PREFIX}/lib/libXvMCNVIDIA_dynamic.so.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
