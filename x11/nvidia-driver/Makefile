# New ports collection makefile for:	nvidia-driver
# Date created:				4 December 2002
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	nvidia-driver
DISTVERSION?=	100.14.11
PORTREVISION?=	0			# For consistency with slave ports
CATEGORIES=	x11 kld
MASTER_SITES=	${MASTER_SITE_NVIDIA}
MASTER_SITE_SUBDIR=	freebsd/${DISTVERSION}
DISTNAME=	NVIDIA-FreeBSD-x86-${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering

ONLY_FOR_ARCHS=	i386

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel
USE_GL=		gl
USE_LDCONFIG=	yes
SUB_FILES+=	pkg-message
DOCSDIR=	${PREFIX}/share/doc/NVIDIA_GLX-1.0
PORTDOCS=	*

OPTIONS=	FREEBSD_AGP	"Use FreeBSD AGP GART driver" off \
		VM86_INT10CALL	"Use VM86 interface for video BIOS calls" off \
		ACPI		"Enable support for ACPI Power Management" off \
		LINUX		"Build with support for Linux compatibility" on

# Starting with version 7667, NVidia has dropped support for numerous
# "legacy" GPUs.  Consult NVidia README (the Appendix) to find out whether
# you need to use legacy driver version and install one of corresponding
# `x11/nvidia-driver-71xx' or `x11/nvidia-driver-96xx' slave ports.
#
.if ${DISTVERSION:M1.0-*}
NVVERSION=	${DISTVERSION:S/1.0-//}
.else
NVVERSION=	${DISTVERSION:S/.//g}
.endif

EXTRA_PATCHES+=	${FILESDIR}/7667-patch-lib::Makefile

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM} == "xorg"
MODULESDIR=	lib/xorg/modules
XORG_SUB=	""
XFREE86_SUB=	"@comment "
.else
MODULESDIR=	lib/modules
XORG_SUB=	"@comment "
XFREE86_SUB=	""
.endif

# XXX Should use ${PKG_INFO} XXX
#
XSERVVERSION!=	/usr/sbin/pkg_info -O x11-servers/XFree86-4-Server 2>/dev/null | ${GREP} Server- || /usr/sbin/pkg_info -O x11-servers/xorg-server 2>/dev/null | ${GREP} server- || /usr/sbin/pkg_info -qO x11-servers/xorg-server-snap 2>/dev/null
XLIBVERSION!=	/usr/sbin/pkg_info -O x11/XFree86-4-libraries 2>/dev/null | ${GREP} libraries- || /usr/sbin/pkg_info -O graphics/libGL 2>/dev/null | ${GREP} libGL- || true

.if empty(XSERVVERSION)
IGNORE=		needs an X server implementation installed
.endif

PLIST_SUB+=	XSERVVERSION=${XSERVVERSION} XLIBVERSION=${XLIBVERSION} \
		LINUXBASE=${LINUXBASE} SHLIB_VERSION=${PORTVERSION} \
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

.if ${OSVERSION} >= 600033
LIB_DEPENDS+=	m.3:${PORTSDIR}/misc/compat5x
.endif

post-patch: .SILENT
# We should support -CURRENT: kill the check
.if ${NVVERSION} >= 7174
	${REINPLACE_CMD} '24,26d' ${WRKSRC}/src/nv-freebsd.h
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
# Don't build any binaries (nvidia-settings and nvidia-xconfig)
.if ${NVVERSION} < 9746
	${REINPLACE_CMD} -E 's/(extension).*/\1/' ${WRKSRC}/x11/Makefile
.else
	${REINPLACE_CMD} -E 's/(lib).*/\1/' ${WRKSRC}/x11/Makefile
.endif
	${REINPLACE_CMD} '/bin/d ; /man/d' ${WRKSRC}/x11/Makefile
# Conditionally install documentation (but you generally want it)
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -E 's/(x11).*/\1/ ; /doc/d' ${WRKSRC}/Makefile
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
# Do not execute afterinstall target (prevent automatic module registration)
	${REINPLACE_CMD} -e 's/afterinstall/dontexecute/' ${WRKSRC}/Makefile

pre-su-install:
	@${MKDIR} ${PREFIX}/${MODULESDIR}/drivers

post-install:
# pkg-plist is already overbloated, so use this hack instead of PLIST_SUB's
.if ${NVVERSION} < 8174
	@${REINPLACE_CMD} '/libnvidia-cfg/d' ${TMPPLIST}
.else
	@${REINPLACE_CMD} '/nvidia_drv\.o/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 9746
	@${REINPLACE_CMD} '/wfb/d' ${TMPPLIST}
.endif
	@${LN} -sf libXvMCNVIDIA.so.1 ${PREFIX}/lib/libXvMCNVIDIA_dynamic.so.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
