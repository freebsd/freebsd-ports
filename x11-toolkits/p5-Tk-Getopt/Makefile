# New ports collection makefile for:	p5-Tk-Getopt
# Date created:				May 28 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	Tk-Getopt
PORTVERSION=	0.48
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${LOCALBASE}/lib/perl5/${PERL_VERSION}
MAN3=		Tk::Getopt.3

.include <bsd.port.mk>
