# New ports collection makefile for:   xfishtank
# Version required:    2.2
# Date created:        24th April 1997
# Whom:                jacs
#
# $FreeBSD$
#

DISTNAME=      xfishtank-2.2
CATEGORIES=    x11
MASTER_SITES=  ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=    jacs@gnome.co.uk

USE_IMAKE=     yes
WRKSRC=                ${WRKDIR}/xfishtank2.0
NO_INSTALL_MANPAGES=yes

post-patch:
	cd  ${WRKDIR}/xfishtank2.0; make clean

.include <bsd.port.mk>
