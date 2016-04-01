# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tk-Action
PORTVERSION=	1.093390
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Action abstraction for Tk

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.92:devel/p5-Moose \
		p5-MooseX-Has-Sugar>=0:devel/p5-MooseX-Has-Sugar \
		p5-MooseX-SemiAffordanceAccessor>=0:devel/p5-MooseX-SemiAffordanceAccessor \
		p5-Tk-Sugar>=0:x11-toolkits/p5-Tk-Sugar
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
