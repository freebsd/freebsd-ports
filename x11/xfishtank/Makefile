# New ports collection makefile for:   xfishtank
# Version required:    2.2
# Date created:        24th April 1997
# Whom:                jacs
#
# $Id: Makefile,v 1.1.1.1 1997/06/17 06:47:57 tg Exp $
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
