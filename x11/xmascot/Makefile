# New ports collection makefile for:	xmascot
# Date created:		20 November 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xmascot
PORTVERSION=	2.6a
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://cclub-flying.dsl.gr.jp/products/xmascot/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Moving mascot on your X11 screen

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAN1=		xmascot.1

post-install:
	-@${MKDIR} ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults
	${CP} ${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/XMascot ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults/

.include <bsd.port.mk>
