# New ports collection makefile for:	Ruby-qt
# Date created:		12 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	0.11
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	http://sfns.u-shizuoka-ken.ac.jp/geneng/horie_hp/ruby/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	${QTLIB}.${QTLIB_SHLIBVER}:${PORTSDIR}/x11-toolkits/${QT_PORTNAME}
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-qt-include=${X11BASE}/include/X11/qt \
		--with-qt-lib=${X11BASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

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
	${PERL} -i -pe ' \
		s,/usr/X11\b,${X11BASE},g; \
		' ${WRKSRC}/lib/qt.rb

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/qt
	${CP} -R ${WRKSRC}/examples/ ${PREFIX}/share/examples/ruby/qt/
	${MKDIR} ${PREFIX}/share/doc/ruby/qt/ja
	${CP} -R ${WRKSRC}/tutorial ${PREFIX}/share/doc/ruby/qt/
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/ruby/qt/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/ruby/qt/ja/
.endif

.include <bsd.port.mk>
