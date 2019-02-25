# Created by: mr
# $FreeBSD$

PORTNAME=	Wx-GLCanvas
PORTVERSION=	0.09
PORTREVISION=	3
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MBARBON
PKGNAMEPREFIX=	p5-

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Perl interface to wxWidgets' OpenGL canvas

BUILD_DEPENDS=  p5-OpenGL>=0.66:graphics/p5-OpenGL \
		p5-Wx>=0.5000:x11-toolkits/p5-Wx
RUN_DEPENDS=    p5-OpenGL>=0.66:graphics/p5-OpenGL \
		p5-Wx>=0.5000:x11-toolkits/p5-Wx

#MANUAL_PACKAGE_BUILD=	needs the X server it will be used with to build

PORTSCOUT=	limit:^[0-9\.]*$$

USES=           compiler:c++11-lib perl5
USE_CXXSTD=     c++11
USE_PERL5=      configure
USE_WX=         3.0
CONFIGURE_ENV=  CXX="${CXX}"

CFLAGS+=        -pthread -Wno-write-strings -I${LOCALBASE}/include

post-configure:
	@${FIND} ${WRKSRC} -name "Makefile" -type f | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|$$(CC)|$$(CXX)|g ; \
		s|$$(CCFLAGS)|$$(CXXFLAGS)|g'

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
