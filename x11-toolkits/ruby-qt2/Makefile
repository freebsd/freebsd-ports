# New ports collection makefile for:	Ruby-qt2
# Date created:		9 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt2
PORTVERSION=	0.11
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	http://sfns.u-shizuoka-ken.ac.jp/geneng/horie_hp/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	qt2.4:${PORTSDIR}/x11-toolkits/qt22

USE_MESA=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-qt2-include=${X11BASE}/include/qt2 \
		--with-qt2-lib=${X11BASE}/lib \
		--with-qt2=qt2 \
		--with-x11-dir=${X11BASE}
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

post-extract:
	find ${WRKSRC} '(' -name .cvsignore -o -name a.out ')' -delete

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/qt2
	${CP} -R ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/qt2/
	${MKDIR} ${RUBY_DOCDIR}/qt2/ja
	${CP} -R ${WRKSRC}/tutorial ${RUBY_DOCDIR}/qt2/
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_DOCDIR}/qt2/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${RUBY_DOCDIR}/qt2/ja/
.endif

.include <bsd.port.mk>
