# New ports collection makefile for:    XFree86
# Date created:         5 January 1995
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	XFree86
PORTVERSION= 	3.3.6
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	X336src-1.tgz X336src-2.tgz

PATCH_SITES=	ftp://ftp.xfree.org/pub/XFree86/3.3.6/fixes/ \
		ftp://ftp.freesoftware.com/pub/XFree86/3.3.6/fixes/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-3.3.6/fixes/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/3.3.6/fixes/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/3.3.6/fixes/
PATCHFILES= 	fix-01-r128 fix-04-s3trio3d2x fix-05-s3trio3d fix-06-s3trio3d2x\
		fix-07-s3trio64v2gx+netfinity fix-08-s3savage_ix+mx   

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/${DIST_SUBDIR}
INSTALLS_SHLIB=	yes
.if (${MACHINE} != "alpha")
#NO_PACKAGE=	package available from XFree86
.endif
ALL_TARGET=	World
INSTALL_TARGET=	install install.man
DIST_SUBDIR=	xc
PATCH_DIST_ARGS=-p2 -E -d ${WRKDIR}/xc/programs --quiet
SCRIPTS_ENV=	OSVERSION=${OSVERSION}
# can't use USE_X_PREFIX here -- it will cause a circular dependency
PREFIX=		${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.if (${MACHINE} == "pc98")
SCRIPTS_ENV+=	MACHINE=pc98
PLIST=		${PKGDIR}/pkg-plist.pc98
.endif
.if (${MACHINE} == "alpha")
SCRIPTS_ENV+=	MACHINE=alpha
PLIST=		${PKGDIR}/pkg-plist.alpha
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
	@if [ -r ${FILESDIR}/config ]; then \
		${ECHO} Using your existing ${FILESDIR}/config ; \
		${CP} ${FILESDIR}/config ${WRKDIR}/config ; \
	fi

.include <bsd.port.pre.mk>

.if !exists(${FILESDIR}/config)
IS_INTERACTIVE=	yes	# configure script asks questions
.endif

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

.include <bsd.port.post.mk>
