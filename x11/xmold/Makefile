# New ports collection makefile for:	xmold
# Date created:		11 October 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xmold
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.cc.tut.ac.jp/pub/xwin/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mold spreading over your X11 screen

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

USE_IMAKE=	yes
USE_XORG=	x11 xext
NO_INSTALL_MANPAGES=	yes
PLIST_FILES=	bin/xmold

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmold ${PREFIX}/bin

.include <bsd.port.mk>
