# New ports collection makefile for:    XFree86-contrib
# Date created:         7 November 1996
# Whom:                 asami
#
# $FreeBSD$
#

PORTNAME=	XFree86-contrib
PORTVERSION=	3.3.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	X336contrib
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	XFree86 contrib programs

# Define FORCE_PACKAGE from the command line if you want to override
# this and build a package
NO_PACKAGE=	"Binary package distributed by XFree86 already"
USE_IMAKE=	yes
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/contrib
MAN1=		ico.1 listres.1 showfont.1 viewres.1 xbiff.1 xcalc.1 \
		xditview.1 xedit.1 xev.1 xeyes.1 xfontsel.1 xgc.1 xload.1 \
		xman.1 xmessage.1

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
IGNORE=		"Only for XFree86 version 3"
.endif

.include <bsd.port.post.mk>
