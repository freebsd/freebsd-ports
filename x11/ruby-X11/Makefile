# New ports collection makefile for:	RubyX11
# Date created:		31 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	X11
PORTVERSION=	0.5
CATEGORIES=	x11 ruby
MASTER_SITES=	http://artengine.ca/matju/RubyX11/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	Ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A fully reflective X11 client library for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		ChangeLog Documentation Overview TODO
EXAMPLES=	tests/*

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/* ${RUBY_SITELIBDIR}/${PORTNAME}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
