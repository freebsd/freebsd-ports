# created by: cmt@FreeBSD.org

PORTNAME=	Gtk3-ImageView
PORTVERSION=	9
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ASOKOLOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Perl bindings to the GtkImageView image viewer widget

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Gtk3>=0.034:x11-toolkits/p5-Gtk3 \
		p5-Glib>=1.163:devel/p5-Glib \
		p5-Readonly>0:devel/p5-Readonly

USES=		gnome perl5
USE_PERL5=	configure
USE_GNOME=	gtk30

NO_ARCH=	yes

.include <bsd.port.mk>
