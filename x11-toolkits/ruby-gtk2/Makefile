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

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_XLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS=	${GTK_CONFIG}
INSTALL_TARGET=	site-install

.if defined(WITHOUT_IMLIB)
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
.else
LIB_DEPENDS+=	Imlib.5:${PORTSDIR}/graphics/imlib
GTK_CONFIG?=	${X11BASE}/bin/imlib-config
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
.if !defined(NO_IMLIB)
	${MKDIR} ${RUBY_EXAMPLESDIR}/gtk/gdkimlib
	${INSTALL_DATA} ${WRKSRC}/sample/gdkimlib/*.rb ${RUBY_EXAMPLESDIR}/gtk/gdkimlib
.endif
	${MKDIR} ${RUBY_DOCDIR}/gtk/ja
	${INSTALL_DATA} ${WRKSRC}/doc/api/* ${RUBY_DOCDIR}/gtk
	${INSTALL_DATA} ${WRKSRC}/doc/api-ja/* ${RUBY_DOCDIR}/gtk/ja
.endif

.include <bsd.port.mk>
