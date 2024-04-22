PORTNAME=	Gtk2-Ex-Dialogs
PORTVERSION=	0.11
PORTREVISION=	7
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Useful tools for Gnome2/Gtk2 Perl GUI design
WWW=		https://metacpan.org/release/Gtk2-Ex-Dialogs

LICENSE=	LGPL21

DEPRECATED=	No longer works with modern Gtk2
EXPIRATION_DATE=2024-04-24

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Type>=0:devel/p5-File-Type \
		p5-Gtk2-Ex-Utils>=0:x11-toolkits/p5-Gtk2-Ex-Utils

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
