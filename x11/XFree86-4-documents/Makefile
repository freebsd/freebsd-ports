# New ports collection makefile for:	XFree86-documents
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	documents
PORTVERSION=	4.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X${PORTVERSION:S/.//g}src-1.tgz X${PORTVERSION:S/.//g}src-2.tgz X${PORTVERSION:S/.//g}src-3.tgz
EXTRACT_ONLY=	X${PORTVERSION:S/.//g}src-2.tgz X${PORTVERSION:S/.//g}src-3.tgz

MAINTAINER=	anholt@freebsd.org

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
		${DISTDIR}/${DIST_SUBDIR}/X${PORTVERSION:S/.//g}src-1.tgz \
		${EXTRACT_AFTER_ARGS} xc/doc)

do-configure:
	(cd ${WRKSRC} ; \
	 ${ECHO_CMD} "#define BuildMiscDocs YES" > host.def ; \
	 ${ECHO_CMD} "#define BuildSpecsDocs YES" >> host.def ; \
	 ${ECHO_CMD} "#define BuildLinuxDocPS NO" >> host.def ; \
	 ${ECHO_CMD} "#define InstallHardcopyDocs YES" >> host.def ; \
	 ${ECHO_CMD} "#define FreeBSDBuildXdoc YES" >> host.def ; \
	 imake -DUseInstalled ${PROJECTROOT} -I. -I${PREFIX}/lib/X11/config \
		-DTOPDIR=.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

.include <bsd.port.mk>
