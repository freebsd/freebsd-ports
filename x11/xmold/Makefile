# New ports collection makefile for:	xmold
# Date created:		11 October 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xmold
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.cc.tut.ac.jp/pub/xwin/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mold spreading over your X11 screen

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
PLIST_FILES=	bin/xmold

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmold ${PREFIX}/bin

.include <bsd.port.mk>
