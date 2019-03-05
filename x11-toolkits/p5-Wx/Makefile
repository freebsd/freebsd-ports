# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Wx
PORTVERSION=	0.9932
PORTREVISION=	4
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the wxWidgets cross-platform GUI toolkit

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BROKEN=		fails to build

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-ExtUtils-XSpp>=0.16.03:devel/p5-ExtUtils-XSpp \
		p5-Alien-wxWidgets>=0.25:x11-toolkits/p5-Alien-wxWidgets

USES=		compiler:c++11-lib perl5
USE_CXXSTD=	c++11
USE_PERL5=	configure
USE_WX=		3.0
CONFIGURE_ENV=	CXX="${CXX}"

CFLAGS+=	-pthread -Wno-write-strings

post-configure:
	@${FIND} ${WRKSRC} -name "Makefile" -type f | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|$$(CC)|$$(CXX)|g ; \
		 s|$$(CCFLAGS)|$$(CXXFLAGS)|g'

pre-build:
	@(cd ${WRKSRC} && ${DO_MAKE_BUILD} generated)

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL} -name "*.so" -type f \
		| ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
