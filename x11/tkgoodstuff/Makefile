# New ports collection makefile for:	tkgoodstuff
# Version required:	4.1
# Date created:		7 Oct 1996
# Whom:			pst
#
# $Id$
#

#PKGNAME=	tkgoodstuff-4.1
DISTNAME=	tkgoodstuff4.1
CATEGORIES+=	x11
MASTER_SITES=	ftp://merv.philosophy.lsa.umich.edu/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pst@FreeBSD.org

RUN_DEPENDS=	fvwm:${PORTSDIR}/x11/fvwm2
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	TCLCONFIGSH=/usr/libdata/tcl/tclConfig.sh TCLSH=/usr/bin/tclsh \
		INSTALL_PROGRAM=""
CONFIGURE_ARGS=	--enable-libs

.include <bsd.port.mk>
