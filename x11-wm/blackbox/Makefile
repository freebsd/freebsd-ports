# New ports collection makefile for:	Blackbox
# Date created:		June 15, 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	blackbox
PORTVERSION=	0.70.0
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	blackboxwm

MAINTAINER=	dako@bsdberlin.org
COMMENT=	A small and fast window manager for X11R6

RUN_DEPENDS=	bsetbg:${PORTSDIR}/x11-wm/boxtools

MAN1=		blackbox.1

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_ICONV=	yes
USE_GNOME=	pkgconfig gnomehack
USE_GCC=	3.3+

post-patch:
	@${REINPLACE_CMD} -e 's#-pedantic##' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's#nls src util#nls src#' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E 's/^SUBDIRS/#SUBDIRS/' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's# bsetroot.1 bsetbg.1##' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
