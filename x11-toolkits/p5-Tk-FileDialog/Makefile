PORTNAME=	Tk-FileDialog
PORTVERSION=	1.3
PORTREVISION=	7
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	File selection dialog for Perl/Tk
WWW=		https://metacpan.org/release/Tk-FileDialog

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	Does not work with recent Tk versions
EXPIRATION_DATE=2024-04-29

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Tk>=0:x11-toolkits/p5-Tk

USES=		perl5
USE_PERL5=	configure

PLIST_SUB=	PERL_VERSION=${PERL_VERSION}

.include <bsd.port.mk>
