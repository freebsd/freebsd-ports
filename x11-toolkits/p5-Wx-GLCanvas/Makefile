# Created by: Tomoyuki Sakurai <y@trombik.org>
# $FreeBSD$

PORTNAME=	Wx-GLCanvas
PORTVERSION=	0.09
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	y@trombik.org
COMMENT=	Interface to wxWidgets OpenGL canvas

LICENSE=	ART10

BUILD_DEPENDS= p5-Wx>=0:x11-toolkits/p5-Wx

USES=		perl5 compiler:c++11-lang
HAS_CONFIGURE=	yes
USE_PERL5=	run configure

do-configure:
	(cd ${BUILD_WRKSRC}; ${SETENV} ${PERL} Makefile.PL)

do-build:
	#(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET} ${MAKE_ARGS})
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE})

.include <bsd.port.mk>
