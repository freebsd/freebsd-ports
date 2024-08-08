PORTNAME=	Test-Tk
PORTVERSION=	3.04
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing Tk widgets
WWW=		https://metacpan.org/dist/Test-Tk

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Tk>=0:x11-toolkits/p5-Tk

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
