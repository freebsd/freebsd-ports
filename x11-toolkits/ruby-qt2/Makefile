# New ports collection makefile for:	Ruby-qt2
# Date created:		9 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt2
PORTVERSION=	${RUBY_QT2_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	${RUBY_QT2_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_QT2_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_QT_VER=	2
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GMAKE=	yes

WRKSRC=		${RUBY_QT2_WRKSRC}
CONFIGURE_ARGS=	${RUBY_QT2_CONFIGURE_ARGS}
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

post-extract:
	${FIND} ${WRKSRC} '(' -name .cvsignore -o -name a.out ')' -delete

post-patch:
	${RUBY} -i -pe 'sub %r"/usr/X11\b", "${X11BASE}"' ${WRKSRC}/lib/qt2.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${CP} -R ${WRKSRC}/tutorial ${WRKSRC}/util \
		${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${WRKSRC}/README.txt \
		${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/CHANGES.jp ${WRKSRC}/README.jp \
		${RUBY_MODDOCDIR}/ja/
.endif

.include "${.CURDIR}/Makefile.common"
.include <bsd.port.mk>
