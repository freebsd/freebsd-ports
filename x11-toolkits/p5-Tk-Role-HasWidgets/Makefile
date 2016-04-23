# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tk-Role-HasWidgets
PORTVERSION=	1.112380
CATEGORIES=	x11-toolkits tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Keep track of your Tk widgets

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Moose>=0.92:devel/p5-Moose \
		p5-MooseX-Has-Sugar>=0:devel/p5-MooseX-Has-Sugar
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
