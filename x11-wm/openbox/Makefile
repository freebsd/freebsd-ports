# New ports collection makefile for:	Blackbox
# Date created:		June 15, 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	blackbox
PORTVERSION=	0.62.0
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	blackboxwm

MAINTAINER=	stijn@win.tue.nl

MAN1=		blackbox.1 bsetroot.1

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

pre-patch:
	@${PERL} -ni.orig -e '/^SUBDIRS/ || print' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
