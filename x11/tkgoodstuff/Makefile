# New ports collection makefile for:	tkgoodstuff
# Version required:	4.1
# Date created:		7 Oct 1996
# Whom:			pst
#
# $Id: Makefile,v 1.5 1997/04/20 13:20:00 wosch Exp $
#

DISTNAME=	tkgoodstuff4.1
PKGNAME=	tkgoodstuff-4.1
CATEGORIES=	x11 tk41
MASTER_SITES=	ftp://merv.philosophy.lsa.umich.edu/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pst@FreeBSD.org

RUN_DEPENDS=	fvwm:${PORTSDIR}/x11/fvwm2
LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	TCLCONFIGSH=/usr/libdata/tcl/tclConfig.sh TCLSH=/usr/bin/tclsh
CONFIGURE_ARGS=	--enable-libs
STRIP=

.include <bsd.port.mk>
