# New ports collection makefile for:	ruby-gtk
# Date created:		19 April 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION= 	0.23
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	http://www.ruby-lang.org/gtk/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	yasuf@bsdclub.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes
USE_GTK=	yes
WANT_IMLIB=	yes

INSTALL_TARGET=	site-install

.include <bsd.port.pre.mk>

.if defined(HAVE_IMLIB)
USE_IMLIB=	yes
.else
PLIST=		${WRKDIR}/PLIST
pre-install:
	@${SED} -e '/gdkimlib/d' ${PKGDIR}/pkg-plist > ${PLIST}
.endif

post-configure:
	${PERL} -i -pe 's/\binstall\b/site-install/g' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.rb ${RUBY_SITELIBDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/gtk
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/gtk
	${MKDIR} ${RUBY_EXAMPLESDIR}/gtk/browser
	${INSTALL_DATA} ${WRKSRC}/doc/*.rb ${RUBY_EXAMPLESDIR}/gtk/browser
.if defined(HAVE_IMLIB)
	${MKDIR} ${RUBY_EXAMPLESDIR}/gtk/gdkimlib
	${INSTALL_DATA} ${WRKSRC}/sample/gdkimlib/*.rb ${RUBY_EXAMPLESDIR}/gtk/gdkimlib
.endif
	${MKDIR} ${RUBY_DOCDIR}/gtk/ja
	${INSTALL_DATA} ${WRKSRC}/doc/api/* ${RUBY_DOCDIR}/gtk
	${INSTALL_DATA} ${WRKSRC}/doc/api-ja/* ${RUBY_DOCDIR}/gtk/ja
.endif

.include <bsd.port.post.mk>
