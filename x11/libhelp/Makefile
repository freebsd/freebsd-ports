# New ports collection makefile for:	libhelp
# Date created:		11 December 96
# Whom:			Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
#
# $FreeBSD$
#

PORTNAME=	libhelp
PORTVERSION=	1.8.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.informatik.uni-stuttgart.de/pub/libhelp/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.de

USE_MOTIF= 	YES
USE_IMAKE=	YES
NO_INSTALL_MANPAGES= YES

post-install:
	@${MKDIR} ${X11BASE}/lib/X11/xmhelp/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${X11BASE}/lib/X11/xmhelp/pixmaps
	@${MKDIR} ${X11BASE}/lib/X11/xmhelp/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${X11BASE}/lib/X11/xmhelp/help

.include <bsd.port.mk>
