# New ports collection makefile for:    XFree86
# Version required:     3.3.6
# Date created:         5 January 1995
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	xc
PKGNAME= 	XFree86-3.3.6
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.6/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/3.3.6/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-3.3.6/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/3.3.6/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3.6/source/
DISTFILES=	X336src-1.tgz X336src-2.tgz

PATCH_SITES=	ftp://ftp.xfree.org/pub/XFree86/3.3.6/fixes/ \
		ftp://ftp.freesoftware.com/pub/XFree86/3.3.6/fixes/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-3.3.6/fixes/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/3.3.6/fixes/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3.6/fixes/
PATCHFILES= 	fix-01-r128	

MAINTAINER=	jmz@FreeBSD.org

IS_INTERACTIVE=	yes	# configure script asks questions
.if (${MACHINE} != "alpha")
#NO_PACKAGE=	package available from XFree86
.endif
ALL_TARGET=	World
INSTALL_TARGET=	install install.man
DIST_SUBDIR=	xc
PATCH_DIST_ARGS=-p0 -E -d ${WRKDIR} --quiet
SCRIPTS_ENV=	OSVERSION=${OSVERSION}
# can't use USE_X_PREFIX here -- it will cause a circular dependency
PREFIX=		${X11BASE}
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

.include <bsd.port.pre.mk>

pre-install:
	${MKDIR} ${X11BASE}

post-install:
.if ${PORTOBJFORMAT} == "aout"
.for lib in PEX5 SM XIE Xi Xmu Xt oldX XThrStub
	${LN} -sf lib${lib}.so.6.0 ${PREFIX}/lib/lib${lib}.so
.endfor
.for lib in X11 Xaw Xtst
	${LN} -sf lib${lib}.so.6.1 ${PREFIX}/lib/lib${lib}.so
.endfor
.for lib in Xp
	${LN} -sf lib${lib}.so.6.2 ${PREFIX}/lib/lib${lib}.so
.endfor
.for lib in ICE Xext
	${LN} -sf lib${lib}.so.6.3 ${PREFIX}/lib/lib${lib}.so
.endfor
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
