# New ports collection makefile for:	Ruby-kde
# Date created:		14 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kde
PORTVERSION=	0.11
CATEGORIES=	x11 kde	# ruby
MASTER_SITES=	http://sfns.u-shizuoka-ken.ac.jp/geneng/horie_hp/ruby/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	kdecore.${KDELIB_SHLIBVER}:${PORTSDIR}/x11/${KDE_PORTNAME}
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/qt.rb:${PORTSDIR}/x11-toolkits/${RUBY_QT_PORTNAME}

INSTALL_TARGET=	site-install

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

QTLIBDIR=	${X11BASE}/lib
QTINCDIR=	${X11BASE}/include/X11/qt
KDELIBDIR=	${LOCALBASE}/lib
KDEINCDIR=	${LOCALBASE}/include

.if defined(WITH_I18N)
QTLIB=		qti18n
KDELIB_SHLIBVER=	2
KDE_PORTNAME=	kdelibs11-i18n
RUBY_QT_PORTNAME=	ruby-qt-i18n
.else
QTLIB=		qt
KDELIB_SHLIBVER=	3
KDE_PORTNAME=	kdelibs11
RUBY_QT_PORTNAME=	ruby-qt
.endif

post-patch:
	${PERL} -i -pe ' \
		s,%%X11BASE%%,${X11BASE},g; \
		s,%%I18NQT%%,${I18NQT},g; \
		s,%%QTLIBDIR%%,${QTLIBDIR},g; \
		s,%%QTINCDIR%%,${QTINCDIR},g; \
		s,%%KDELIBDIR%%,${KDELIBDIR},g; \
		s,%%KDEINCDIR%%,${KDEINCDIR},g; \
		s,%%QTLIB%%,${QTLIB},g; \
		' ${WRKSRC}/extconf.rb

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/kde
	${CP} -R ${WRKSRC}/examples/ ${PREFIX}/share/examples/ruby/kde/
	${MKDIR} ${PREFIX}/share/doc/ruby/kde/ja
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/ruby/kde/
	${INSTALL_DATA} ${WRKSRC}/README.jp.txt ${PREFIX}/share/doc/ruby/kde/ja/
.endif

.include <bsd.port.mk>
