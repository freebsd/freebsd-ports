PORTNAME=	Gtk2-Ex-FormFactory
PORTVERSION=	0.67
PORTREVISION=	5
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Makes building complex GUI more easy
WWW=		https://metacpan.org/release/Gtk2-Ex-FormFactory

LICENSE=	GPLv2+

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Glib>=1.00:devel/p5-Glib \
		p5-Gtk2>=1.060:x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Ex-Simple-List>=0:x11-toolkits/p5-Gtk2-Ex-Simple-List

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
