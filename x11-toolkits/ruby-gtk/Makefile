# New ports collection makefile for:	ruby-gtk
# Date created:		19 April 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby binding for GTK+

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes
USE_GNOME=	gtk12

.include "${.CURDIR}/../../x11/ruby-gnome/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/${PORTNAME}
CONFIGURE_ARGS=	--with-gtk-config=${GTK_CONFIG}
INSTALL_TARGET=	site-install

DOCS_EN=	BUGS \
		ChangeLog \
		NEWS \
		README \
		README.EXT \
		ToDo
DOCS_JA=	README.EXT.ja

post-extract:
	${MKDIR} ${WRKSRC}/sample/browser
	${MV} ${WRKSRC}/doc/*.rb ${WRKSRC}/sample/browser/

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/gtkcompat.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
