# New ports collection makefile for:	Ruby-FLTK
# Date created:		25 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION=	20000831
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	http://kt-www.jaist.ac.jp/~ttate/ftp/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_MESA=	yes

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-0.1
INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-fltk-dir="${X11BASE}" --with-gl-dir="${X11BASE}"
MAKE_ARGS=	LOCAL_LIBS="-lgcc"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/fltk
	${INSTALL_DATA} ${WRKSRC}/test/*.rb ${RUBY_EXAMPLESDIR}/fltk/
	${MKDIR} ${RUBY_DOCDIR}/fltk/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/fltk/
	${INSTALL_DATA} ${WRKSRC}/README.euc.jp ${WRKSRC}/README.utf8 ${RUBY_DOCDIR}/fltk/ja/
.endif

.include <bsd.port.mk>
