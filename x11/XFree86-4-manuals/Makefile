# New ports collection makefile for:	XFree86-4-manuals-4.0.1
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	manuals
PORTVERSION=	4.0.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.0.2
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X402src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

XFREE86_VERSION=	4
USE_IMAKE=		YES
EXTRACT_TARGET=		xc/doc/man \
 			xc/extras/ogl-sample/main/doc/man
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - ${EXTRACT_TARGET}
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc/doc/man
INSTALL_TARGET=		install.man

.include <bsd.port.pre.mk>
.include <${FILESDIR}/manpages>

do-configure:
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

.include <bsd.port.post.mk>
