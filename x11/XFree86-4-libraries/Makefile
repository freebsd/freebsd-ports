# New ports collection makefile for:	XFree86Xlibraries-4.0
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	libraries
PORTVERSION=	4.0.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/${PORTVERSION}/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/${PORTVERSION}/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-${PORTVERSION}/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/${PORTVERSION}/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/${PORTVERSION}/source/
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X401src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4

XFREE86_VERSION=	4
XFREE86_HTML_MAN=	yes
PREFIX?=		${X11BASE}
MTREE_FILE=		/etc/mtree/BSD.x11-4.dist
INSTALLS_SHLIB=		yes
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
SCRIPTS_ENV+=		PREFIX=${PREFIX} \
			X11BASE=${X11BASE} \
			WRKDIR=${WRKDIR} \
			DISTDIR=${DISTDIR}
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET= FreeBSDPortsInstall FreeBSDPortsInstall.man installXlib
MANCOMPRESSED=	yes
MAN1=		libxrx.1
MAN3=		Xaw.3

.if defined(XDM_DES)
.if ${USA_RESIDENT} == YES
pre-fetch:
	@${ECHO}
	@${ECHO} Assuming that you have fetched a USA-Legal Wraphelp.c.
.else
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
EXTRACT_ONLY=	X401src-1.tgz
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif
.endif

.include <bsd.port.mk>
