# New ports collection makefile for:	xrsh
# Date created: 	30 May 2004
# Whom:			KIMURA Yasuhiro <yasu@utahime.org>
#
# $FreeBSD$
#

PORTNAME=	xrsh
PORTVERSION=	5.92
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://jjd.com/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Launcher which starts an X program on a remote machine

USE_IMAKE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=
MAN1=		xrsh.1 xrlogin.1

PLIST_FILES=	bin/xrsh bin/xrlogin

.include <bsd.port.mk>
