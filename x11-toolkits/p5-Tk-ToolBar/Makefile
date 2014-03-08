# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tk-ToolBar
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolbar widget for Perl/Tk

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tk-CursorControl>=0:${PORTSDIR}/x11-toolkits/p5-Tk-CursorControl
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod

USE_PERL5=	configure
USES=		perl5 zip

.include <bsd.port.mk>
