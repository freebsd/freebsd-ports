# New ports collection makefile for:	Ruby-qt
# Date created:		12 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	0.14a
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	http://sfns.u-shizuoka-ken.ac.jp/geneng/horie_hp/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	qt.3:${PORTSDIR}/x11-toolkits/qt145

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-qti18n \
		--with-qt-include=${X11BASE}/include/X11/qt \
		--with-qt-lib=${X11BASE}/lib
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

post-patch:
	${RUBY} -i -pe 'gsub %r"/usr/X11\b", "${X11BASE}"' ${WRKSRC}/lib/qt.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/qt
	${TAR} -C ${WRKSRC}/examples -cf - \
		--exclude .cvsignore --exclude a.out . \
			| ${TAR} -C ${RUBY_EXAMPLESDIR}/qt -xvf -
	${MKDIR} ${RUBY_DOCDIR}/qt/ja
	${TAR} -C ${WRKSRC} -cf - \
		./tutorial \
			| ${TAR} -C ${RUBY_DOCDIR}/qt -xvf -
	${CHOWN} -R 0:0 ${RUBY_EXAMPLESDIR}/qt ${RUBY_DOCDIR}/qt
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_DOCDIR}/qt/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${RUBY_DOCDIR}/qt/ja/
.endif

.include <bsd.port.mk>
