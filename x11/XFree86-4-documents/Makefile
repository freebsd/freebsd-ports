# New ports collection makefile for:	XFree86-4-documents-4.0.1
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	documents
PORTVERSION=	4.0.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.0.2
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X402src-1.tgz X402src-2.tgz X402src-3.tgz
EXTRACT_ONLY=	X402src-2.tgz X402src-3.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

XFREE86_VERSION=	4
USE_IMAKE=		YES
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc/doc
DEFFILE=		${PREFIX}/lib/X11/config/FreeBSD.ports.def
INSTALL_TARGET=		install install.man

post-extract:
	(cd ${WRKDIR} && \
	 ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/X402src-1.tgz \
		${EXTRACT_AFTER_ARGS} xc/doc)

do-configure:
	(cd ${WRKSRC} ; \
	 ${ECHO} "#define BuildMiscDocs YES" > host.def ; \
	 ${ECHO} "#define BuildSpecsDocs YES" >> host.def ; \
	 ${ECHO} "#define BuildLinuxDocPS NO" >> host.def ; \
	 ${ECHO} "#define InstallHardcopyDocs YES" >> host.def ; \
	 ${ECHO} "#define FreeBSDBuildXdoc YES" >> host.def ; \
	 imake -DUseInstalled ${PROJECTROOT} -I. -I${PREFIX}/lib/X11/config \
		-DTOPDIR=.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

.include <bsd.port.mk>
