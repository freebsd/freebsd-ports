# New ports collection makefile for:	Blackbox
# Date created:		June 15, 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	blackbox
PORTVERSION=	0.65.0
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	blackboxwm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small and fast window manager for X11R6

RUN_DEPENDS=	bsetbg:${PORTSDIR}/x11-wm/boxtools

MAN1=		blackbox.1

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

pre-patch:
	${REINPLACE_CMD} -e 's#-pedantic##' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's#nls src util#nls src#' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -E 's/^SUBDIRS/#SUBDIRS/' ${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's# bsetroot.1 bsetbg.1##' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
