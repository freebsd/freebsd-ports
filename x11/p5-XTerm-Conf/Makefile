# $FreeBSD$

PORTNAME=	XTerm-Conf
PORTVERSION=	0.10
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SREZIC
PKGNAMEPREFIX=	p5-

MAINTAINER=	slaven@rezic.de
COMMENT=	Perl module that changes configuration of a running xterm

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Term-ReadKey>=2.32:devel/p5-Term-ReadKey

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
