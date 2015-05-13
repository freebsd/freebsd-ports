# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Wx
PORTVERSION=	0.99.27
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the wxWidgets cross-platform GUI toolkit

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Alien-wxWidgets>=0.25:${PORTSDIR}/x11-toolkits/p5-Alien-wxWidgets \
		p5-ExtUtils-XSpp>=0.16.03:${PORTSDIR}/devel/p5-ExtUtils-XSpp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 compiler:c++11-lib
USE_PERL5=	configure
USE_WX=		3.0
USE_CXXSTD=	c++11
WX_COMPS=	wx
WX_UNICODE=	1
CC=		${CXX}
CFLAGS+=	-pthread -Wno-write-strings
CONFIGURE_ENV=	CXX=${CXX}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
BROKEN=		does not build
.endif

post-configure:
	@${FIND} ${WRKSRC} -name "Makefile" -type f | ${XARGS} \
		${REINPLACE_CMD} -e 's|^CCFLAGS = .*$$|CCFLAGS = ${CXXFLAGS}|'

.include <bsd.port.post.mk>
