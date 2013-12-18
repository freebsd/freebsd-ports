# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pango
PORTVERSION=	1.224
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XAOC
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl module for layout and render i18n text

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.300:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.03:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Cairo>=1:${PORTSDIR}/graphics/p5-Cairo \
		p5-Glib2>=1.220:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS=	p5-Glib2>=1.220:${PORTSDIR}/devel/p5-Glib2

USE_GNOME=	pango
USES=		perl5
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
