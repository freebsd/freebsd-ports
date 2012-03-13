# New ports collection makefile for:	p5-Tk-Role-Dialog
# Date created:		2011-10-10
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-Role-Dialog
PORTVERSION=	1.112.380
CATEGORIES=	x11-toolkits tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Moose role for enhanced Tk dialogs

BUILD_DEPENDS=	p5-Moose>=0.92:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Has-Sugar>=0:${PORTSDIR}/devel/p5-MooseX-Has-Sugar \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-Tk-Role-HasWidgets>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/p5-Tk-Role-HasWidgets \
		p5-Tk-Sugar>=0:${PORTSDIR}/x11-toolkits/p5-Tk-Sugar
RUN_DEPENDS=	p5-Moose>=0.92:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Has-Sugar>=0:${PORTSDIR}/devel/p5-MooseX-Has-Sugar \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-Tk-Role-HasWidgets>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/p5-Tk-Role-HasWidgets \
		p5-Tk-Sugar>=0:${PORTSDIR}/x11-toolkits/p5-Tk-Sugar

PERL_MODBUILD=	5.10.0+

MAN3=		Tk::Role::Dialog.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
