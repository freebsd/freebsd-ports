PORTNAME=	viewklass
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ViewKlass-${PORTVERSION}
DISTNAME=	ViewKlass-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Framework for Motif
WWW=		https://viewklass.sourceforge.net/

LICENSE=	LGPL20+

USES=		imake:env motif
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CFLAGS=/s|-g|${CFLAGS}| ; \
		 /^CXXFLAGS=/s|-g|${CXXFLAGS}| ; \
		 s| $$(exec_prefix)| $$(DESTDIR)$$(exec_prefix)| ; \
		 s| $$(prefix)| $$(DESTDIR)$$(prefix)|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
