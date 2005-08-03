# New ports collection makefile for:	FXRuby
# Date created:		24 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	1.0.29
PORTREVISION=	1
CATEGORIES=	x11-toolkits ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fxruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	FXRuby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby extension module to use FOX, aka FXRuby

#BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	FOX-1.0.0:${PORTSDIR}/x11-toolkits/fox \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		fxscintilla.17:${PORTSDIR}/x11-toolkits/fxscintilla-fox10

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
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
