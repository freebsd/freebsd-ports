# New ports collection makefile for:	XFree86Xdocuments-4.0
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	documents
PORTVERSION=	4.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/4.0/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/4.0/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-4.0/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/4.0/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/4.0/source/
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X400src-1.tgz X400src-2.tgz
EXTRACT_ONLY=	X400src-2.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4

PREFIX?=	${X11BASE}
PROJECTROOT=	-DProjectRoot=${PREFIX}
MTREE_FILE=	/etc/mtree/BSD.x11.dist
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc/doc
DEFFILE=	${PREFIX}/lib/X11/config/FreeBSD.ports.def
INSTALL_TARGET=	install install.man

post-extract:
	(cd ${WRKDIR} && \
	 ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/X400src-1.tgz \
		${EXTRACT_AFTER_ARGS} xc/doc)

do-configure:
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DBuildMiscDocs=YES -DBuildSpecsDocs=YES \
		-DBuildLinuxDocPS=NO \
		-DFreeBSDBuildXdoc=YES \
		-DTOPDIR=.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

.include <bsd.port.mk>
