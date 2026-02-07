PORTNAME=	Gtk2-Ex-Utils
PORTVERSION=	0.09
PORTREVISION=	10
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extra Gtk2 utilities for Gtk2 in perl
WWW=		https://metacpan.org/release/Gtk2-Ex-Utils

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Glib>=1.00:devel/p5-Glib \
		p5-ExtUtils-Depends>=0.3:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.1:devel/p5-ExtUtils-PkgConfig \
		p5-Gtk2>=1.060:x11-toolkits/p5-Gtk2 \
		p5-Cairo>=0:graphics/p5-Cairo
RUN_DEPENDS=	p5-Glib>=1.00:devel/p5-Glib \
		p5-Gtk2>=1.060:x11-toolkits/p5-Gtk2

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
