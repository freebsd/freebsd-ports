# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Wx
PORTVERSION=	0.99.23
PORTREVISION=	1
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	Perl5 interface to the wxWidgets cross-platform GUI toolkit

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Alien-wxWidgets>=0.25:${PORTSDIR}/x11-toolkits/p5-Alien-wxWidgets \
		p5-ExtUtils-XSpp>=0.16.03:${PORTSDIR}/devel/p5-ExtUtils-XSpp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_WX=		3.0
WX_COMPS=	wx
WX_UNICODE=	1
CC=		${CXX}
CFLAGS+=	-pthread -Wno-write-strings
CONFIGURE_ENV=	CXX=${CXX}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501508
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=3.15:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
RUN_DEPENDS+=	p5-ExtUtils-ParseXS>=3.15:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
.endif


post-configure:
	@${FIND} ${WRKSRC} -name "Makefile" -type f | ${XARGS} \
		${REINPLACE_CMD} -e 's/^CCFLAGS = .*$$/CCFLAGS = ${CFLAGS}/'

.include <bsd.port.post.mk>
