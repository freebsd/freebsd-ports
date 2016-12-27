# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	X11
PORTVERSION=	0.5
CATEGORIES=	x11 ruby
MASTER_SITES=	http://artengine.ca/matju/RubyX11/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	Ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fully reflective X11 client library for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		ChangeLog Documentation Overview TODO
EXAMPLES=	tests/*

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/* ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}/
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
