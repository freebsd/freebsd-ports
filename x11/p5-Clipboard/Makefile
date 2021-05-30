# Created by: Anton Berezin <tobez@FreeBSD.org>

PORTNAME=	Clipboard
PORTVERSION=	0.28
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SHLOMIF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Access to X11 clipboard from Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI>=0:www/p5-CGI \
		p5-URI>=0:net/p5-URI \
		xclip:x11/xclip

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
