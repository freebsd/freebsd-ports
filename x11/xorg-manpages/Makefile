# New ports collection makefile for:	xorg-manpages
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	xorg-manpages
PORTVERSION=	6.8.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R${PORTVERSION}/src
DISTNAME=	X11R${PORTVERSION}-src
DISTFILES=	X11R${PORTVERSION}-src1.tar.gz \
		X11R${PORTVERSION}-src3.tar.gz
EXTRACT_ONLY=	X11R${PORTVERSION}-src1.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org library manual pages

CONFLICTS=	XFree86-manuals-*

EXTRA_PATCHES=	${CF_PATCHES}

XMAN_DIRS=	lib/Xaw lib/Xcursor lib/Xrandr doc/man programs/Xserver
XINCLUDE_DIRS=	${XMAN_DIRS}

post-extract:
	(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/X11R${PORTVERSION}-src3.tar.gz | \
		${TAR} -xf - xc/programs/Xserver);

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	is part of X.Org
.endif

.include "${FILESDIR}/manpages"

.include <bsd.port.post.mk>
