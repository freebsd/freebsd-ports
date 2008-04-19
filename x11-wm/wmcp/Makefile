# New ports collection makefile for:	wmcp
# Date created:			10 February 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmcp
PORTVERSION=	1.2.8
PORTREVISION=	2
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	http://web.cs.mun.ca/~gstarkes/wmaker/dockapps/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockable pager for Window Maker

PLIST_FILES=	bin/wmcp
USE_XORG=	x11 xext xpm
ALL_TARGET=	clean wmcp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmcp ${PREFIX}/bin

.include <bsd.port.mk>
