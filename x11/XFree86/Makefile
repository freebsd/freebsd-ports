# New ports collection makefile for:    XFree86
# Date created:         5 January 1995
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	XFree86
PORTVERSION=	3.3.6
PORTREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	X336src-1.tgz X336src-2.tgz
.if defined(BUILD_XDIST)
DISTFILES+=	X336src-3.tgz
.endif

PATCH_SITES=	${MASTER_SITE_LOCAL:S,%SUBDIR%,jmz,g}
PATCHFILES=	3.3.6-3.3.6a.diffs.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11R6.3/XFree86 core distribution
DEPRECATED=	Obsolete version, use xorg or XFree86-4 instead
EXPIRATION_DATE=2006-12-01

LATEST_LINK=	XFree86-3
WRKSRC=		${WRKDIR}/${DIST_SUBDIR}
SCRIPTDIR=	${WRKDIR}/scripts
INSTALLS_SHLIB=	yes
ALL_TARGET=	World
INSTALL_TARGET=	install install.man
.if defined(BUILD_XDIST)
INSTALL_TARGET+=	install.linkkit
.endif
DIST_SUBDIR=	xc
SCRIPTS_ENV=	OSVERSION=${OSVERSION} MACHINE=${MACHINE} \
		MACHINE_ARCH=${MACHINE_ARCH}
MAKE_ARGS=	WORLDOPTS=
# can't use USE_X_PREFIX here -- it will cause a circular dependency
PREFIX=		${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.if (${MACHINE} == "pc98")
PLIST=		${PKGDIR}/pkg-plist.pc98
.endif
.if (${MACHINE} == "alpha")
PLIST=		${PKGDIR}/pkg-plist.alpha
.endif

.ifdef USE_XLIB
.error You have `USE_XLIB' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.if defined(XDM_DES) && (${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO)
pre-fetch:
	@${ECHO}
	@${ECHO} You must set variable USA_RESIDENT to YES or NO.
	@${FALSE}
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == NO
pre-fetch:
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
EXTRACT_ONLY=	X336src-1.tgz X336src-2.tgz
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif
.if ${USA_RESIDENT} == YES
pre-fetch:
	@${ECHO}
	@${ECHO} Assuming that you have fetched a USA-Legal Wraphelp.c.
.endif
.endif

post-extract:
	@${MV} ${WRKSRC}/programs/Xserver/hw/xfree86/vga256/drivers/i810/os-support/linux/agpgart.h ${WRKSRC}/programs/Xserver/hw/xfree86/vga256/drivers/i810/
.if defined(BUILD_XDIST)
	@${CP} ${WRKSRC}/programs/Xserver/hw/xfree86/LinkKit/README \
		${WRKSRC}/programs/Xserver/hw/xfree86/doc/sgml
	@${MV} ${WRKSRC}/programs/Xserver/hw/xfree86/doc/sgml/DGux.sgml \
		${WRKSRC}/programs/Xserver/hw/xfree86/doc/sgml/DGUX.sgml
.endif
	@if [ -r ${FILESDIR}/config ]; then \
		${ECHO} Using your existing ${FILESDIR}/config ; \
		${CP} ${FILESDIR}/config ${WRKDIR}/config ; \
	fi

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 601104
BROKEN=		Does not build on FreeBSD >= 6.x
.endif

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
IGNORE= is part of XFree86-3
.endif

.if !defined(BUILD_XDIST) && !exists(${FILESDIR}/config)
IS_INTERACTIVE=	yes	# configure script asks questions
.endif

pre-configure:
	@${MKDIR} ${SCRIPTDIR}
.if defined(BUILD_XDIST)
	@${CP} ${MASTERDIR}/scripts/configure.build_xdist ${SCRIPTDIR}/configure
.else
	@${CP} ${MASTERDIR}/scripts/configure ${SCRIPTDIR}
.endif

pre-install:
	${MKDIR} ${X11BASE}

.include <bsd.port.post.mk>
