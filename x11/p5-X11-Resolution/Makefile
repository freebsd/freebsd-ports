# New ports collection makefile for:    x11/p5-X11-Resolution
# Date created:                         2009-10-24 11:30
# Whom:                                 Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	X11-Resolution
PORTVERSION=	0.0.0
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Provides a method to get the resolution for a X11 screen

RUN_DEPENDS=	${SITE_PERL}/X11/Protocol.pm:${PORTSDIR}/x11/p5-X11-Protocol

PERL_CONFIGURE=	yes

MAN3=		X11::Resolution.3

.include <bsd.port.mk>
