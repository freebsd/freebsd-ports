# New ports collection makefile for:   w9wm
# Date created:        25 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	w9wm
PORTVERSION=	0.4.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://inferno.cs.univ-paris8.fr/~drieu/w9wm/src/

MAINTAINER=	greid@ukug.uk.freebsd.org

USE_X_PREFIX=	yes
MAKEFILE=	Makefile.no-imake

MAN1=		w9wm.1

pre-patch:
	@${PERL} -pi.orig -e 's|malloc.h|stdlib.h|' ${WRKSRC}/client.c

.include <bsd.port.mk>
