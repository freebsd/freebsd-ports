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
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

FOX_VERSION=	0.99.189
#FXRUBY_REVISION=	
.if defined(FXRUBY_REVISION) && !empty(FXRUBY_REVISION)
FXRUBY_PORTVERSION=	${FOX_VERSION}.${FXRUBY_REVISION}
FXRUBY_DISTNAME=	FXRuby-${FOX_VERSION}-${FXRUBY_REVISION}
.else
FXRUBY_PORTVERSION=	${FOX_VERSION}
FXRUBY_DISTNAME=	FXRuby-${FOX_VERSION}
.endif

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

USE_XLIB=	yes
USE_MESA=	yes

DOCS_EN=	ANNOUNCE	ChangeLog	README	\
		index.html	doc

post-patch:
	${RUBY} -i -p \
		-e 'gsub %r:/usr/local\b:, "${LOCALBASE}"' \
		-e 'gsub %r:/usr/X11R6\b:, "${X11BASE}"' \
		${WRKSRC}/ext/fox/extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS_EN}
	${CP} -R ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
