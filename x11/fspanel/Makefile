# New ports collection makefile for:	fspanel
# Date created:		17 jan 2001
# Whom:			The Anarcat <anarcat@anarcat.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	fspanel
PORTVERSION=	0.8.b1
CATEGORIES=	x11
MASTER_SITES=	http://www.chatjunkies.org/fspanel/
DISTNAME=	fspanel-0.8beta1

MAINTAINER=	anarcat@anarcat.dyndns.org
COMMENT=	Tiny panel listing opened windows for gnome-compliant WM

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/Xft

USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
PLIST_FILES=	bin/fspanel
ALL_TARGET=	fspanel

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fspanel ${PREFIX}/bin

.include <bsd.port.mk>
