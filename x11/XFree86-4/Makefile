# New ports collection makefile for:    XFree86
# Date created:         5 January 1995
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	XFree86
PORTVERSION= 	4.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/4.0/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/4.0/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-4.0/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/4.0/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/4.0/source/
DISTFILES=	X400src-1.tgz X400src-2.tgz

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/${DIST_SUBDIR}
.if (${MACHINE} != "alpha")
#NO_PACKAGE=	package available from XFree86
.endif
ALL_TARGET=	World
INSTALL_TARGET=	install install.man
DIST_SUBDIR=	xc
PATCH_DIST_ARGS=-p0 -E -d ${WRKDIR} --quiet
SCRIPTS_ENV=	OSVERSION=${OSVERSION}
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
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.if (${MACHINE} == "pc98")
SCRIPTS_ENV+=	MACHINE=pc98
PLIST=		${PKGDIR}/PLIST.pc98
.endif
.if (${MACHINE} == "alpha")
SCRIPTS_ENV+=	MACHINE=alpha
PLIST=		${PKGDIR}/PLIST.alpha
.endif

.if defined(XDM_DES) && (${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO)
pre-fetch:
	@${ECHO}
	@${ECHO} You must set variable USA_RESIDENT to YES or NO.
	@${FALSE}
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == NO
pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	${SH} ${PKGDIR}/INSTALL
.endif
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
EXTRACT_ONLY=	X400src-1.tgz X400src-2.tgz
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif
.if ${USA_RESIDENT} == YES
pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	${SH} ${PKGDIR}/INSTALL
.endif
	@${ECHO}
	@${ECHO} Assuming that you have fetched a USA-Legal Wraphelp.c.
.endif
.endif

.include <bsd.port.pre.mk>

pre-install:
	${MKDIR} ${PREFIX}

post-install:
.ifndef DISTRIB
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.endif

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
