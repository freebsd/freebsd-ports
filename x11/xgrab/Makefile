# New ports collection makefile for:    xgrab
# Version required:     2.3
# Date created:         27 February 1995
# Whom:                 jmz
#
# $Id: Makefile,v 1.4 1995/04/12 20:32:02 asami Exp $
#

DISTNAME=	xgrabsc.2_3
PKGNAME=	xgrab-2.3
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.sunet.se/pub/X11/R5contrib/

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/app-defaults  -f
# Needs to actually *run* xrdb
IS_INTERACTIVE=	yes
# "make depend" blows up
XMKMF=		xmkmf

.include <bsd.port.mk>
