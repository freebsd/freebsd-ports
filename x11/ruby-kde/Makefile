# New ports collection makefile for:	Ruby-kde
# Date created:		14 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	0.15
CATEGORIES=	x11 kde ruby
MASTER_SITES=	http://sfns.u-shizuoka-ken.ac.jp/geneng/horie_hp/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/qt.rb:${PORTSDIR}/x11-toolkits/ruby-qt

USE_KDELIBS_VER=	1
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-x-dir=${X11BASE} \
		--with-qti18n \
		--with-qt-include=${X11BASE}/include/X11/qt \
		--with-qt-lib=${X11BASE}/lib \
		--with-kde-dir=${LOCALBASE}
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/kde
	${CP} -R ${WRKSRC}/examples/ ${RUBY_EXAMPLESDIR}/kde/
	${MKDIR} ${RUBY_DOCDIR}/kde/ja
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_DOCDIR}/kde/
	${INSTALL_DATA} ${WRKSRC}/README.jp.txt ${RUBY_DOCDIR}/kde/ja/
.endif

.include <bsd.port.mk>
