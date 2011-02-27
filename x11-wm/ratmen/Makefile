# New ports collection makefile for:	ratmen
# Date created:				2008-02-20
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	ratmen
PORTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.update.uu.se/~zrajm/programs/ratmen/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple program for displaying a menu in a window

USE_XORG=	x11
USE_PERL5_BUILD=yes
MAN1=		ratmen.1
PLIST_FILES=	bin/ratmen

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratmen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ratmen.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
