# New ports collection makefile for:	Ruby-panel-applet
# Date created:		20 March 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	panel-applet
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	x11 ruby gnome
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk \
		${RUBY_SITEARCHLIBDIR}/gnome.so:${PORTSDIR}/x11/ruby-gnome

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_GNOME=	yes

.include "${.CURDIR}/../../x11/ruby-gnome/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/${PORTNAME}
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
