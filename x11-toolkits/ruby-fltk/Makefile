# New ports collection makefile for:	Ruby-FLTK
# Date created:		25 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fltk
PORTVERSION=	20000618
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	http://kt-www.jaist.ac.jp:8000/~ttate/ftp/
PKGNAMEPREFIX=	ruby-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

USE_MESA=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-fltk-dir="${X11BASE}" --with-gl-dir="${X11BASE}"
MAKE_ARGS=	LOCAL_LIBS="-lgcc"

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/fltk
	${INSTALL_DATA} ${WRKSRC}/test/adjuster.rb ${PREFIX}/share/examples/ruby/fltk/
	${MKDIR} ${PREFIX}/share/doc/ruby/fltk/ja
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ruby/fltk/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/ruby/fltk/ja/
.endif

.include <bsd.port.mk>
