# New ports collection makefile for:	Ruby-GNOME2
# Date created:		28 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11 ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A set of Ruby bindings for GNOME2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR}/gnomecanvas2.so:${PORTSDIR}/graphics/ruby-gnomecanvas2

USE_RUBY=	yes
USE_GNOME=	libgnomeui
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes

.include "${.CURDIR}/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/gnome
INSTALL_TARGET=	site-install

DOCS_EN=	AUTHORS \
		ChangeLog \
		README \
		README.gnome2-all

post-extract:
	${CP} ${RUBY_GNOME_WRKSRC}/AUTHORS ${WRKSRC}/AUTHORS
	${CP} ${RUBY_GNOME_WRKSRC}/README ${WRKSRC}/README.gnome2-all

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
