# New ports collection makefile for:	Ruby-qt
# Date created:		12 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	0.13
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	http://sfns.u-shizuoka-ken.ac.jp/geneng/horie_hp/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	${QTLIB}.${QTLIB_SHLIBVER}:${PORTSDIR}/x11-toolkits/${QT_PORTNAME}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-qt-include=${X11BASE}/include/X11/qt \
		--with-qt-lib=${X11BASE}/lib
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

.if defined(WITH_I18N)
I18NQT=		-DI18NQT
QTLIB=		qti18n
QTLIB_SHLIBVER=	3
QT_PORTNAME=	qt-i18n
CONFIGURE_ARGS+=	--with-qti18n=qti18n
.else
QTLIB=		qt
QTLIB_SHLIBVER=	3
QT_PORTNAME=	qt145
.endif

post-patch:
	${RUBY} -i -pe 'gsub %r"/usr/X11\b", "${X11BASE}"' ${WRKSRC}/lib/qt.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/qt
	${CP} -R ${WRKSRC}/examples/ ${RUBY_EXAMPLESDIR}/qt/
	${MKDIR} ${RUBY_DOCDIR}/qt/ja
	${CP} -R ${WRKSRC}/tutorial ${RUBY_DOCDIR}/qt/
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_DOCDIR}/qt/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${RUBY_DOCDIR}/qt/ja/
.endif

.include <bsd.port.mk>
