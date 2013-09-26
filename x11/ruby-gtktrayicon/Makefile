# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	gtktrayicon
PORTVERSION=	0.1.0
PORTREVISION=	8
CATEGORIES=	x11 gnome ruby
MASTER_SITES=	SF/ruby-gnome2/OldFiles
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-gtktrayicon-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GtkTrayIcon

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2

USE_RUBY=	yes
USE_GNOME=	gtk20
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=		COPYING.LIB ChangeLog NEWS README

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
