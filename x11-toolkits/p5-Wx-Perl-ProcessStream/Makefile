# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Wx-Perl-ProcessStream
PORTVERSION=	0.32
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module to access IO of external processes via events

BUILD_DEPENDS=	p5-Wx>=0.50:${PORTSDIR}/x11-toolkits/p5-Wx
RUN_DEPENDS=	p5-Wx>=0.50:${PORTSDIR}/x11-toolkits/p5-Wx

USE_WX=		2.6+
WX_COMPS=	wx contrib
WX_UNICODE=	yes
USE_DISPLAY=	yes
PERL_CONFIGURE=	yes

MAN3=		Wx::Perl::ProcessStream.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar
.endif

.include <bsd.port.post.mk>
