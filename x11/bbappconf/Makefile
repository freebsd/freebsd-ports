# New ports collection makefile for:	bbappconf
# Date created:				26 July 2004
# Whom:				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	bbappconf
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/bbtools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Application configuring tool for the blackbox window manager

USE_XORG=	x11
GNU_CONFIGURE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bbappconf ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/bbtools
.for a in README.bbappconf bbappconf.bb bbappconf.nobb
	@${INSTALL_DATA} ${WRKSRC}/data/${a} ${PREFIX}/share/bbtools
.endfor

.include <bsd.port.mk>
