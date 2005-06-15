# New ports collection makefile for:	XFree86-manuals
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	manuals
PORTVERSION=	4.5.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-${PORTVERSION}-src-1.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 man pages

CONFLICTS=	xorg-manpages-[0-9]*

USE_IMAKE=		yes
EXTRACT_TARGET=		xc/doc/man \
			xc/extras/ogl-sample/main/doc/man
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - ${EXTRACT_TARGET}
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc/doc/man
CFGDIR=			${WRKDIR}/xc/config
INSTALL_TARGET=		install.man

pre-configure:
	@${MKDIR} ${CFGDIR}
	@${CP} ${PREFIX}/lib/X11/config/* ${CFGDIR}
	@${ECHO} "#define BuildHtmlManPages NO" >>${CFGDIR}/xf86site.def
	@${ECHO} "#define PreprocessManPages YES" >>${CFGDIR}/xf86site.def

do-configure:
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${PROJECTROOT} -I${CFGDIR} \
		-DTOPDIR=../.. -DCURDIR=.; \
	 ${MAKE} Makefiles CONFIGDIR=${CFGDIR} ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE=	is part of XFree86-4
.endif

.include "${FILESDIR}/manpages"

.include <bsd.port.post.mk>
