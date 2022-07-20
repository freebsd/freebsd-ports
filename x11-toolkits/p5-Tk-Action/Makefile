PORTNAME=	Tk-Action
PORTVERSION=	1.093390
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action abstraction for Tk

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=0.92:devel/p5-Moose \
		p5-MooseX-Has-Sugar>=0:devel/p5-MooseX-Has-Sugar \
		p5-MooseX-SemiAffordanceAccessor>=0:devel/p5-MooseX-SemiAffordanceAccessor \
		p5-Tk-Sugar>=0:x11-toolkits/p5-Tk-Sugar

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
