# New ports collection makefile for:	XFree86-documents
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	documents
PORTVERSION=	4.3.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X430src-1.tgz \
		X430src-6.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 documentation

USE_IMAKE=		YES
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc/doc/specs

do-configure:
	(cd ${WRKSRC} ; \
	 ${ECHO_CMD} "#define BuildMiscDocs YES" > host.def ; \
	 ${ECHO_CMD} "#define BuildSpecsDocs YES" >> host.def ; \
	 ${ECHO_CMD} "#define BuildLinuxDocPS NO" >> host.def ; \
	 ${ECHO_CMD} "#define InstallHardcopyDocs YES" >> host.def ; \
	 ${ECHO_CMD} "#define FreeBSDBuildXdoc YES" >> host.def ; \
	 imake -DUseInstalled ${PROJECTROOT} -I. -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
