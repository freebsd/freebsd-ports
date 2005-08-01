# New ports collection makefile for:	Ruby-GNOME2
# Date created:		28 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	x11 ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A set of Ruby bindings for GNOME2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gnomecanvas2.so:${PORTSDIR}/graphics/ruby-gnomecanvas2

USE_RUBY=	yes
USE_GNOME=	libgnomeui
USE_REINPLACE=	yes
USE_RUBY_EXTCONF=	yes

.include "${.CURDIR}/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/gnome
INSTALL_TARGET=	site-install

DOCS_EN=	AUTHORS COPYING.LIB ChangeLog README README.gnome2-all

post-build:
	@${CP} ${RUBY_GNOME_WRKSRC}/AUTHORS ${WRKSRC}/AUTHORS
	@${CP} ${RUBY_GNOME_WRKSRC}/README ${WRKSRC}/README.gnome2-all

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}/test-gnome
	@${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_MODEXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/sample/test-gnome/* ${RUBY_MODEXAMPLESDIR}/test-gnome/
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
