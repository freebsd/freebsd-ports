# New ports collection makefile for:	XFree86-manuals
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	manuals
PORTVERSION=	4.3.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X${PORTVERSION:S/.//g}src-1.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 man pages

CONFLICTS=	xorg-manpages-*

USE_IMAKE=		YES
EXTRACT_TARGET=		xc/doc/man \
			xc/extras/ogl-sample/main/doc/man
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - ${EXTRACT_TARGET}
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc/doc/man
INSTALL_TARGET=		install.man

do-configure:
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif

.include "${FILESDIR}/manpages"

.include <bsd.port.post.mk>
