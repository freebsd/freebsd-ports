# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Gtk2-Unique
PORTVERSION=	0.05
#PORTREVISION=	0
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Perl binding for the C library libunique

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2
LIB_DEPENDS=	libunique-1.0.so:x11-toolkits/unique
RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_GNOME=	gconf2
USE_PERL5=	configure

.include <bsd.port.mk>
