# New ports collection makefile for:	FXRuby
# Date created:		24 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	${FXRUBY_PORTVERSION}
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fxruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${FXRUBY_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

#BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/SWIG-devel
LIB_DEPENDS=	FOX.1:${PORTSDIR}/x11-toolkits/fox \
		png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

FOX_VERSION=	0.99.166
FXRUBY_REVISION=	1
.if defined(FXRUBY_REVISION) && !empty(FXRUBY_REVISION)
FXRUBY_PORTVERSION=	${FOX_VERSION}.${FXRUBY_REVISION}
FXRUBY_DISTNAME=	FXRuby-${FOX_VERSION}-${FXRUBY_REVISION}
.else
FXRUBY_PORTVERSION=	${FOX_VERSION}
FXRUBY_DISTNAME=	FXRuby-${FOX_VERSION}
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_XLIB=	yes
USE_MESA=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src
INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-fox-include="${LOCALBASE}/include/fox" \
		--with-fox-lib="${LOCALBASE}/lib"
#MAKE_ARGS=	LOCAL_LIBS="-lgcc"

DOCS_EN=	README	index.html

post-patch:
	${RUBY} -i -pe 'sub %r:/usr/X11R6\b:, "${X11BASE}"' ${WRKSRC}/extconf.rb

pre-build:
#	cd ${WRKSRC}/../swig-interfaces; ${MAKE}
	${RUBY} -i -pe 'sub %r:^CXXFLAGS *=.*:, "CXXFLAGS = $$(CFLAGS) $$(CPPFLAGS)"' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/fox
	${CP} -R ${WRKSRC}/../examples/* ${RUBY_EXAMPLESDIR}/fox/
	${MKDIR} ${RUBY_DOCDIR}/fox
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/../${f} ${RUBY_DOCDIR}/fox/
.endfor
.endif

.include <bsd.port.mk>
