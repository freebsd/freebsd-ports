# $FreeBSD$

PORTNAME=	Gtk2-TrayIcon
PORTVERSION=	0.06
PORTREVISION=	5
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BORUP
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the EggTrayIcon library

BUILD_DEPENDS=	p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends	\
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
