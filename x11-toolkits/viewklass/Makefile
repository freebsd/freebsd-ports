# Created by: ijliao
# $FreeBSD$

PORTNAME=	viewklass
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ViewKlass-${PORTVERSION}
DISTNAME=	ViewKlass-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Framework for Motif

LICENSE=	LGPL20 # (or later)

USES=		imake:env motif
USE_AUTOTOOLS=	autoconf213

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CFLAGS=/s|-g|@CFLAGS@| ; \
		 /^CXXFLAGS=/s|-g|@CXXFLAGS@| ; \
		 s| $$(exec_prefix)| $$(DESTDIR)$$(exec_prefix)| ; \
		 s| $$(prefix)| $$(DESTDIR)$$(prefix)|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
