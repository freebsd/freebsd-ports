# New ports collection makefile for:	Ruby/GnomePrintUI
# Date created:				15 November 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/ruby-gnomeprintui/Makefile,v 1.2 2005/10/17 07:05:42 mezz Exp $
#

PORTNAME=	gnomeprintui
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits ruby gnome
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for libgnomeprintui

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gnomeprint2.so:${PORTSDIR}/print/ruby-gnomeprint

USE_RUBY=	yes
USE_GNOME=	libgnomeprintui
USE_RUBY_EXTCONF=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/gnomeprintui
INSTALL_TARGET=	site-install

DOCS=		COPYING.LIB ChangeLog README

post-patch: general-patch

# Have to do that to generate ruby-gnomeprint's rblibgnomeprintversion.h or
# it will not build.
pre-configure:
	@(cd ${RUBY_GNOME_WRKSRC}/gnomeprint ; ${SETENV} ${CONFIGURE_ENV} \
		${RUBY} ${RUBY_FLAGS} ${RUBY_EXTCONF} ${CONFIGURE_ARGS})

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
