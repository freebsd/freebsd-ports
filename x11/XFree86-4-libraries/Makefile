# New ports collection makefile for:	XFree86Xlibraries-4.0
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	libraries
PORTVERSION=	4.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/4.0/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/4.0/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-4.0/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/4.0/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/4.0/source/
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X400src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4

PREFIX?=	${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11.dist
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc
SCRIPTS_ENV+=	PREFIX=${PREFIX} X11BASE=${X11BASE} \
		WRKDIR=${WRKDIR} DISTDIR=${DISTDIR}
ALL_TARGET=	FreeBSDPortsBuild
.if defined(NO_INSTALL_MANPAGES)
INSTALL_TARGET= FreeBSDPortsInstall installXlib
.else
INSTALL_TARGET= FreeBSDPortsInstall FreeBSDPortsInstall.man installXlib
MANCOMPRESSED=	yes
MAN1=		bdftopcf.1 \
		mkfontdir.1
MAN3=		Xaw.3
.endif

.if defined(XDM_DES)
.if ${USA_RESIDENT} == YES
pre-fetch:
	@${ECHO}
	@${ECHO} Assuming that you have fetched a USA-Legal Wraphelp.c.
.else
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
EXTRACT_ONLY=	X400src-1.tgz
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif
.endif

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
