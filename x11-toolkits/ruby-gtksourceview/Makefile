# New ports collection makefile for:	Ruby/GtkSourceView
# Date created:				15 August 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtksourceview
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	x11-toolkits gnome ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Ruby binding for GtkSourceView

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2

USE_RUBY=	yes
USE_GNOME=	gtksourceview
USE_RUBY_EXTCONF=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/gtksourceview
INSTALL_TARGET=	site-install

DOCS=		COPYING.LIB ChangeLog README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
