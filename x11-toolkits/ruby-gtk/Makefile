# New ports collection makefile for:	ruby-gtk
# Date created:		19 April 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	yasuf@bsdclub.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes
USE_GTK=	yes

.include "${.CURDIR}/../../x11/ruby-gnome/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/${PORTNAME}
CONFIGURE_ARGS=	${GTK_CONFIG}
INSTALL_TARGET=	site-install

DOCS_EN=	BUGS \
		ChangeLog \
		ENVIRONMENT \
		README \
		README.EXT \
		ToDo
DOCS_JA=	README.ja \
		README.EXT.ja

post-extract:
	${MKDIR} ${WRKSRC}/sample/browser
	${MV} ${WRKSRC}/doc/rbbr.rb ${WRKSRC}/sample/browser

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
