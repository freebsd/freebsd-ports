# New ports collection makefile for:	p5-Tk-Autoscroller
# Date created:				May 28 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	Tk-Autoscroll
PORTVERSION=	1.11
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk::Autoscroll - space invaders-like scrolling

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${LOCALBASE}/lib/perl5/${PERL_VERSION}
MAN3=		Tk::Autoscroll.3

.include <bsd.port.mk>
