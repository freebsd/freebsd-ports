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

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Ruby binding for GTK+2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/atk.so:${PORTSDIR}/accessibility/ruby-atk \
		${RUBY_SITEARCHLIBDIR}/gdk_pixbuf2.so:${PORTSDIR}/graphics/ruby-gdk_pixbuf2 \
		${RUBY_SITEARCHLIBDIR}/pango.so:${PORTSDIR}/x11-toolkits/ruby-pango

USE_RUBY=	yes
USE_XLIB=	yes
USE_GNOME=	gtk20
USE_RUBY_EXTCONF=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/gtk
INSTALL_TARGET=	site-install

DOCS=		COPYING.LIB ChangeLog README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}/gtk-demo
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}/misc
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}/testgtk
	@${INSTALL_DATA} ${WRKSRC}/sample/gtk-demo/* ${RUBY_MODEXAMPLESDIR}/gtk-demo/
	@${INSTALL_DATA} ${WRKSRC}/sample/misc/* ${RUBY_MODEXAMPLESDIR}/misc/
	@${INSTALL_DATA} ${WRKSRC}/sample/testgtk/* ${RUBY_MODEXAMPLESDIR}/testgtk/
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
