# New ports collection makefile for:	ruby-gnome
# Date created:		28 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnome
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11 ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A set of Ruby bindings for GNOME

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk \
		${RUBY_SITELIBDIR}/gdk_imlib.rb:${PORTSDIR}/graphics/ruby-gdk_imlib \
		${RUBY_SITEARCHLIBDIR}/libart.so:${PORTSDIR}/graphics/ruby-libart

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes
USE_GNOME=	yes

.include "${.CURDIR}/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/${PORTNAME}
CONFIGURE_ARGS=	${GNOME_CONFIG}
INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog \
		NEWS \
		README \
		ToDo

post-extract:
	${MKDIR} ${WRKSRC}/sample/browser
	${MV} ${WRKSRC}/doc/*.rb ${WRKSRC}/sample/browser

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
