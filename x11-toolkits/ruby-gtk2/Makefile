# New ports collection makefile for:	Ruby/GTK2
# Date created:		19 April 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	gtk2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	mezz7@cox.net
COMMENT=	Ruby binding for GTK+2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/atk.so:${PORTSDIR}/accessibility/ruby-atk \
		${RUBY_SITEARCHLIBDIR}/gdk_pixbuf2.so:${PORTSDIR}/graphics/ruby-gdk_pixbuf2 \
		${RUBY_SITEARCHLIBDIR}/pango.so:${PORTSDIR}/x11-toolkits/ruby-pango

USE_RUBY=	yes
USE_GNOME=	gtk20
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/gtk
INSTALL_TARGET=	site-install

DOCS=		ChangeLog \
		README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
