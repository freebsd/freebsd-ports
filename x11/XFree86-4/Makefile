# New ports collection makefile for:    XFree86
# Date created:         5 January 1995
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	XFree86
PORTVERSION=	4.1.0
PORTREVISION=	12
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.1.0
DISTFILES=	X410src-1.tgz X410src-2.tgz
EXTRACT_ONLY=	X410src-1.tgz X410src-2.tgz
MAINTAINER=	jmz@FreeBSD.org

LATEST_LINK=	XFree86-4

WRKSRC=		${WRKDIR}/${DIST_SUBDIR}
.if (${MACHINE} != "alpha")
#NO_PACKAGE=	package available from XFree86
.endif
ALL_TARGET=	World
INSTALL_TARGET=	install install.man
DIST_SUBDIR=	xc
PATCH_DIST_ARGS=-p0 -E -d ${WRKDIR} --quiet
SCRIPTS_ENV=	OSVERSION=${OSVERSION}
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
MAKE_ARGS=	WORLDOPTS=
.ifdef DISTRIB
DESTDIR=	${WRKDIR}/distrib
MAKE_ENV+=	DESTDIR=${DESTDIR}
NO_PKG_REGISTER=yes
SCRIPTS_ENV+=	NO_INPUT=yes
.endif
# can't use USE_X_PREFIX here -- it will cause a circular dependency
PREFIX=		${X11BASE}
.if defined(DISTRIB) || defined(PACKAGE_BUILDING)
#IS_INTERACTIVE is boolean -- "no" is the same as defining it "yes"!
#IS_INTERACTIVE=	no
.else
IS_INTERACTIVE=	yes	# configure script asks questions
.endif
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
.if (${MACHINE} == "pc98")
SCRIPTS_ENV+=	MACHINE=pc98
PLIST=		${PKGDIR}/pkg-plist.pc98
.endif
.if (${MACHINE} == "alpha")
SCRIPTS_ENV+=	MACHINE=alpha
PLIST=		${PKGDIR}/pkg-plist.alpha
.endif

pre-configure:
	@if ${ECHO} "$(CFLAGS)" |${GREP} -q O[3456789]; then \
		${ECHO} "XFree86-4 with thread support does not build with optimization"; \
		${ECHO} "flags different from O or -O2"; \
		${FALSE}; fi

.if defined(XDM_DES) && (${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO)
pre-fetch:
	@${ECHO}
	@${ECHO} You must set variable USA_RESIDENT to YES or NO.
	@${FALSE}
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == NO
pre-fetch:
.ifndef WITH_MATROX_GXX_DRIVER
	@${ECHO} Define WITH_MATROX_GXX_DRIVER if you want to enable Matrox driver for 
	@${ECHO} G200, G400, G450 and G550 graphic adapters
.endif
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.else # ${USA_RESIDENT} == YES
pre-fetch:
	@${ECHO}
	@${ECHO} Assuming that you have fetched a USA-Legal Wraphelp.c.
.ifndef WITH_MATROX_GXX_DRIVER
	@${ECHO} Define WITH_MATROX_GXX_DRIVER if you want to enable Matrox driver for 
	@${ECHO} G200, G400, G450 and G550 graphic adapters
.endif
.endif # ${USA_RESIDENT}
.endif

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 410000
BROKEN=	"can't be compiled on this system (missing headers)"
.endif

.if defined(WITH_MATROX_GXX_DRIVER)
MGA_DRIVER_VERSION=	133_143
MGA_DRIVER_DIR=		1.4.3
MASTER_SITES+=	ftp://ftp.matrox.com/pub/mga/archive/linux/2001/beta_${MGA_DRIVER_VERSION}/
DISTFILES+=	mga-${MGA_DRIVER_VERSION}-source.tgz

PLIST_SUB+=	MATROX_GXX=""
.else
PLIST_SUB+=	MATROX_GXX="@comment "
.endif # WITH_MATROX_GXX_DRIVER


.if ${OSVERSION} > 500012
post-patch:
	@if [ ! -e ${WRKSRC}/include/Xarch.h.orig ]; then\
	  mv ${WRKSRC}/include/Xarch.h ${WRKSRC}/include/Xarch.h.orig;\
	  ${SED} -e 52d -e 54d < ${WRKSRC}/include/Xarch.h.orig > \
	  ${WRKSRC}/include/Xarch.h; fi
.endif # ${OSVERSION} > 500012
.if defined(WITH_MATROX_GXX_DRIVER)
.if !target(post-patch)
post-patch:
.endif # !target(post-patch)
	@${MV} ${WRKSRC}/programs/Xserver/hw/xfree86/drivers/mga \
		${WRKSRC}/programs/Xserver/hw/xfree86/drivers/mga.old
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/mga-${MGA_DRIVER_VERSION}-source.tgz \
		-C ${WRKDIR}
	@${MV} ${WRKDIR}/mgasource/mga-${MGA_DRIVER_DIR}/mga \
		${WRKSRC}/programs/Xserver/hw/xfree86/drivers
	@${CP} ${WRKSRC}/config/cf/xf86site.def ${WRKSRC}/config/cf/host.def
	@${ECHO} "#define HaveMatroxHal YES" >> ${WRKSRC}/config/cf/host.def
	@${PERL} -pi.orig -ne 's!(#define PCI_CHIP_MGAG400\s+0x0525)!\1\n#define PCI_CHIP_MGAG550 0x2527\n!; \
			s!({PCI_CHIP_MGAG400,\s+"MGA G400 AGP",0},)!\1\n{PCI_CHIP_MGAG550, "MGA G550 AGP", 0},\n!' \
			${WRKSRC}/programs/Xserver/hw/xfree86/common/xf86PciInfo.h
.endif # WITH_MATROX_GXX_DRIVER

pre-install:
	${MKDIR} ${PREFIX}

post-install:
.ifndef DISTRIB
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.endif
	@${CAT} ${PKGMESSAGE}

.ifdef DISTRIB
distrib: all install
	@cd ../XFree86-contrib && \
	    ${MAKE} NO_PKG_REGISTER=yes WRKDIR=${WRKDIR}/contrib-work \
	    PREFIX=${X11BASE} PREFIX=${DESTDIR}/${PREFIX} all install
	@${MKDIR} ${WRKDIR}/bindist
	@${CP} ${WRKSRC}/programs/Xserver/hw/xfree86/etc/bindist/FreeBSD-ELF/* \
	    ${WRKDIR}/bindist
	@${SED} -e 's:TAR="gnu-tar":TAR="${TAR}":g' \
	    -e 's/EXTRACTLOPTS="-t -v"/TARLOPTS="-t -v -z"/g' \
	    -e 's/\(#\)\(      echo $$i >> $$LISTFILE\)/\2/g' \
	    -e 's/\(#\)\(      echo "------------" >> $$LISTFILE\)/\2/g' \
	    -e 's/\(#\)\(      $$TAR $$TARLOPTS -f $$i >> $$LISTFILE\)/\2/g' \
	    -e 's/\(#\)\(      echo "" >> $$LISTFILE\)/\2/g' \
	    -e 's/\(      $$EXTRACT $$EXTRACTLOPTS $$i >> $$LISTFILE\)/#\1/g' \
	    < ${WRKSRC}/programs/Xserver/hw/xfree86/etc/bindist/build-bindist \
	    > ${WRKDIR}/build-bindist
	@${CHMOD} 0555 ${WRKDIR}/build-bindist
	@${WRKDIR}/build-bindist X ${WRKDIR}/distrib ${WRKDIR}/bindist
.else
distrib:
	@${ECHO_MSG} '>> The DISTRIB variable must be set when building ' \
	    '"distrib".'
	@exit 1
.endif

.include <bsd.port.post.mk>
