# New ports collection makefile for:	p5-Wx-Perl-ProcessStream
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Wx-Perl-ProcessStream
PORTVERSION=	0.11
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 module to access IO of external processes via events

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Wx.pm:${PORTSDIR}/x11-toolkits/p5-Wx
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Wx.pm:${PORTSDIR}/x11-toolkits/p5-Wx

USE_WX=		2.6+
WX_COMPS=	wx contrib
WX_UNICODE=	yes
USE_DISPLAY=	yes
PERL_CONFIGURE=	yes

MAN3=		Wx::Perl::ProcessStream.3

.include <bsd.port.mk>
