# New ports collection makefile for:    XFree86
# Version required:     3.3.3
# Date created:         5 January 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.50 1998/11/24 01:21:49 asami Exp $
#

DISTNAME=	xc
PKGNAME= 	XFree86-3.3.3.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.3/source/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3.3/source/ \
		ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.3.3/source/ \
		ftp://ftp.uni-stuttgart.de/pub/X11/Xfree86/3.3.3/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3.3/source/
DISTFILES=	X333src-1.tgz X333src-2.tgz

PATCH_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.3.1/fixes/ \
		ftp://xfree86.cdrom.com/pub/XFree86/3.3.3.1/fixes/ \
		ftp://ftp.ibp.fr/pub/X11/XFree86/XFree86-3.3.3.1/fixes/ \
		ftp://ftp.uni-stuttgart.de/pub/X11/Xfree86/3.3.3.1/fixes/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3.3.1/fixes/
PATCHFILES=	3.3.3-3.3.3.1.diff.gz

MAINTAINER=	jmz@FreeBSD.ORG

IS_INTERACTIVE=	yes	# configure script asks questions
NO_PACKAGE=	package available from XFree86
ALL_TARGET=	World
INSTALL_TARGET=	install install.man
DIST_SUBDIR=	xc
PATCH_DIST_ARGS=-p0 -E -d ${WRKDIR} --quiet
# can't use USE_X_PREFIX here -- it will cause a circular dependency
PREFIX=		${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.if (${MACHINE} == "pc98")
SCRIPTS_ENV+=	MACHINE=pc98
PLIST=		${PKGDIR}/PLIST.pc98
.endif

.if defined(XDM_DES) && (${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO)
pre-fetch:
	@${ECHO}
	@${ECHO} You must set variable USA_RESIDENT to YES or NO.
	@false
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == NO
pre-fetch:
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
EXTRACT_ONLY=	X333src-1.tgz X333src-2.tgz
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
.for lib in PEX5 SM XIE Xi Xmu Xt oldX
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
